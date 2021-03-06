/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2014 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_CLASS_REQUIRE_STATEMENT_H_
#define incl_HPHP_CLASS_REQUIRE_STATEMENT_H_

#include "hphp/compiler/statement/statement.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

DECLARE_BOOST_TYPES(ExpressionList);
DECLARE_BOOST_TYPES(StatementList);
DECLARE_BOOST_TYPES(ClassRequireStatement);

class ClassRequireStatement : public Statement, public IParseHandler {
public:
  ClassRequireStatement(STATEMENT_CONSTRUCTOR_PARAMETERS,
                        const std::string &required,
                        bool isExtends);

  DECLARE_STATEMENT_VIRTUAL_FUNCTIONS;
  bool isExtends() const { return m_extends; }
  std::string getRequiredName() const { return m_required;}

  // implementing IParseHandler
  void onParseRecur(AnalysisResultConstPtr ar, FileScopeRawPtr fs,
                    ClassScopePtr scope) override;

private:
  bool m_extends;  // class/interface
  std::string m_required;  // name of class/interface
};

///////////////////////////////////////////////////////////////////////////////
}
#endif // incl_HPHP_CLASS_REQUIRE_STATEMENT_H_
