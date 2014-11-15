#include "Query.h"
#include "TextQuery.h"
#include <set>
#include <algorithm>
#include <iostream>

using std::set;
using std::ostream;
using std::inserter; 
using std::set_difference; 
using std::set_union; 
using std::set_intersection;

// returns lines not in its operand's result set
set<TextQuery::line_no>
NotQuery::eval(const TextQuery& file) const
{
    // virtual call through the Query handle to eval
    set<TextQuery::line_no> has_val = query.eval(file);

    set<line_no> ret_lines;

    // for each line in the input file, check whether that line is in has_val
    // if not, add that line number to ret_lines
    for (TextQuery::line_no n = 0; n != file.size(); ++n)
        if (has_val.find(n) == has_val.end())
            ret_lines.insert(n);
    return ret_lines;
}

// returns intersection of its operands' result sets
set<TextQuery::line_no>
AndQuery::eval(const TextQuery& file) const
{
    // virtual calls through the Query handle to get result sets for the operands
    set<line_no> left = lhs.eval(file), 
                 right = rhs.eval(file);

    set<line_no> ret_lines;  // destination to hold results 

    // writes intersection of two ranges to a destination iterator
    // destination iterator in this call adds elements to ret
    set_intersection(left.begin(), left.end(), 
                  right.begin(), right.end(),
                  inserter(ret_lines, ret_lines.begin()));
    return ret_lines;
}

// returns union of its operands' result sets
set<TextQuery::line_no>
OrQuery::eval(const TextQuery& file) const
{
    // virtual calls through the Query handle to get result sets for the operands
    set<line_no> right = rhs.eval(file),
             ret_lines = lhs.eval(file);  // destination to hold results

    // inserts the lines from right that aren't already in ret_lines
    ret_lines.insert(right.begin(), right.end());

    return ret_lines;
}

