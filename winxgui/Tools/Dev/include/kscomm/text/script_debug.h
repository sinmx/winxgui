/* -------------------------------------------------------------------------
//	文件名		：	text/script_debug.h
//	创建者		：	许式伟
//	创建时间	：	4/24/2003 12:59:38 AM
//	功能描述	：	
//
//	$Id: script_debug.h,v 1.4 2006/06/10 05:39:50 xushiwei Exp $
// -----------------------------------------------------------------------*/
#ifndef __KFC_TEXT_SCRIPT_DEBUG_H__
#define __KFC_TEXT_SCRIPT_DEBUG_H__

_KFC_TEXT_SCRIPT_BEGIN

// -------------------------------------------------------------------------

#include <stdio.h>

class StdioLog
{
public:
	static void Print(const char* szFmt, ...) {
		va_list args;
		va_start(args, szFmt);
		vprintf(szFmt, args);
		va_end(args);
	}
	int Good() const {
		return TRUE;
	}
};

class StderrLog
{
public:
	static void Print(const char* szFmt, ...) {
		va_list args;
		va_start(args, szFmt);
		vfprintf(stderr, szFmt, args);
		va_end(args);
	}
	int Good() const {
		return TRUE;
	}
};

class FileLog
{
private:
	FILE* m_fp;
	BOOL m_fOwn;

public:
	FileLog(FILE* fp = NULL, BOOL fOwn = FALSE) 
		: m_fp(fp), m_fOwn(fOwn) {
	}
	FileLog(LPCSTR szFile) {
		m_fp = fopen(szFile, "w");
		m_fOwn = TRUE;
	}
	~FileLog() {
		if (m_fOwn && m_fp)
			fclose(m_fp);
	}
	int Good() const {
		return m_fp != NULL;
	}
	void Open(FILE* fp, BOOL fOwn = FALSE) {
		ASSERT(m_fp == NULL);
		m_fp = fp;
		m_fOwn = fOwn;
	}
	int Open(LPCSTR szFile) {
		ASSERT(m_fp == NULL);
		m_fp = fopen(szFile, "w");
		if (m_fp == NULL)
			return FALSE;
		m_fOwn = TRUE;
		return TRUE;
	}
	void PrintV(const char* szFmt, va_list args) const {
		if (m_fp)
			vfprintf(m_fp, szFmt, args);
	}
	void Print(const char* szFmt, ...) const {
		if (m_fp) {
			va_list args;
			va_start(args, szFmt);
			vfprintf(m_fp, szFmt, args);
			va_end(args);
		}
	}
};

template <UINT Count>
class MultiLog
{
public:
	FileLog m_log[Count];

public:
	void Print(const char* szFmt, ...) {
		va_list args;
		va_start(args, szFmt);
		for (UINT i = 0; i < Count; ++i)
			m_log[i].PrintV(szFmt, args);
		va_end(args);
	}
};

// -------------------------------------------------------------------------

template <class Log>
inline
STDMETHODIMP_(void) PrintLevel(Log& log, int nLevel)
{
	for (int i = 0; i < nLevel; ++i)
		log.Print("    ");
}

template <class Log>
inline
STDMETHODIMP_(void) PrintLine(Log& log)
{
	log.Print("-------------------------------------------------------\n");
}

template <class Log, class Rule>
STDMETHODIMP_(void) PrintRule(Log& log, Rule& rule, int nLevel);

template <class Log, class RuleList>
STDMETHODIMP_(void) PrintRuleAnd(Log& log, RuleList& rules, int nLevel)
{
	typename RuleList::iterator it;
	for (it = rules.begin(); it != rules.end(); ++it)
	{
		PrintRule(log, *it, 0);
	}
}

template <class Log, class RuleList>
STDMETHODIMP_(void) PrintRuleOr(Log& log, RuleList& rules, int nLevel)
{
	if (rules.empty())
		return;
	typename RuleList::iterator it = rules.begin();
	for (;;)
	{
		PrintRule(*it, 0);
		if (++it == rules.end())
			break;
		log.Print(" |");
	}
}

template <class Log, class Rule>
STDMETHODIMP_(void) PrintRule(Log& log, Rule& rule, int nLevel)
{
	enum RuleType
	{
		match_all = Rule::match_all,
		match_all_regular = Rule::match_all_regular,
		match_string_const = Rule::match_string_const,
		match_mrule = Rule::match_mrule,
		match_rule_and = Rule::match_rule_and,
		match_rule_or = Rule::match_rule_or,
		match_rule_repeat = Rule::match_rule_repeat,
		match_rule_repeat_or_not = Rule::match_rule_repeat_or_not,
		match_has_or_not = Rule::match_has_or_not,
		match_rule_closeer = Rule::match_rule_closeer
	};
	switch (rule.op)
	{
	case match_string_const:
		log.Print(" \"%s\"", rule.string_const->c_str());
		break;
	case match_all:
		log.Print(" $(*");
		if (!rule.mrule->var_name.empty())
			log.Print(" = %s", rule.mrule->var_name.c_str());
		log.Print(")");
		break;
	case match_all_regular:
		log.Print(" $(_regular");
		if (!rule.mrule->var_name.empty())
			log.Print(" = %s", rule.mrule->var_name.c_str());
		log.Print(")");
		break;
	case match_mrule:
		log.Print(" $(%s", rule.mrule->rule_name.c_str());
		if (!rule.mrule->var_name.empty())
			log.Print(" = %s", rule.mrule->var_name.c_str());
		log.Print(")");
		break;
	case match_rule_and:
		PrintRuleAnd(log, *rule.and_rules, nLevel);
		break;
	case match_rule_or:
		PrintRuleOr(log, *rule.or_rules, nLevel);
		break;
	case match_rule_repeat:
		log.Print(" {");
		PrintRule(log, *rule.repeat_rule, nLevel+4);
		log.Print(" }");
		break;
	case match_rule_repeat_or_not:
		log.Print(" *{");
		PrintRule(log, *rule.repeat_rule, nLevel+4);
		log.Print(" }");
		break;
	case match_has_or_not:
		log.Print(" [");
		PrintRule(log, *rule.rule, nLevel+4);
		log.Print(" ]");
		break;
	case match_rule_closeer:
		log.Print(" *[");
		PrintRule(log, *rule.rule, nLevel+4);
		log.Print(" ]");
		break;
	default:
		ASSERT(FALSE);
	}
}

template <class Log, class String, class Rule>
STDMETHODIMP_(void) PrintARule(Log& log, String& rule_name, Rule& rule)
{
	log.Print("%s =", rule_name.c_str());
	PrintRule(log, rule, 4);
	log.Print(";\n");
}

template <class Log, class RuleMap>
STDMETHODIMP_(void) PrintRules(Log& log, RuleMap& rules)
{
	PrintLine(log);
	typename RuleMap::iterator it;
	for (it = rules.begin(); it != rules.end(); ++it)
	{
		PrintARule(log, (*it).first, (*it).second);
	}
}

// -------------------------------------------------------------------------

template <class Log, class NodeList>
STDMETHODIMP_(void) PrintVariantListT(Log& log, NodeList& vars, int nLevel);

template <class Log, class Node>
STDMETHODIMP_(void) PrintAVariant(Log& log, Node& node, int nLevel)
{
	typedef Node::Variant Variant;
	enum VariantType
	{
		vtNone		= Variant::vtNone,
		vtInt		= Variant::vtInt,
		vtAtom		= Variant::vtAtom,
		vtElement	= Variant::vtElement,
	};
	switch (node.value.vt)
	{
	case vtAtom:
		PrintLevel(log, nLevel);
		log.Print("<%s>%s</%s>\n", node.name, node.value.atomVal, node.name);
		break;
	case vtElement:	{
		Node::NodeList& lst = *node.value.lstVal;
		PrintLevel(log, nLevel);
		log.Print("<%s>\n", node.name);
		PrintVariantListT(log, lst, nLevel+1);
		PrintLevel(log, nLevel);
		log.Print("</%s>\n", node.name);
		break;		}
	case vtInt:
		PrintLevel(log, nLevel);
		log.Print("<%s>%d</%s>\n", node.name, node.value.intVal, node.name);
		break;
	default:
		ASSERT(FALSE);
	}
}

template <class Log, class NodeList>
STDMETHODIMP_(void) PrintVariantListT(Log& log, NodeList& vars, int nLevel = 0)
{
	typename NodeList::iterator it;
	for (it = vars.begin(); it != vars.end(); ++it)
	{
		PrintAVariant(log, *it, nLevel);
	}
}

template <class NodeList>
STDMETHODIMP_(void) PrintVariantList(NodeList& vars, int nLevel = 0)
{
	StdioLog log;
	PrintVariantListT(log, vars, nLevel);
}

// -------------------------------------------------------------------------
// $Log: script_debug.h,v $
// Revision 1.4  2006/06/10 05:39:50  xushiwei
// PrintVariantList
//
// Revision 1.3  2006/06/10 05:38:21  xushiwei
// 支持多个Log终端同时输出: stderr, file("_ErrorLog_.txt")
//

_KFC_TEXT_SCRIPT_END

#endif /* __KFC_TEXT_SCRIPT_DEBUG_H__ */
