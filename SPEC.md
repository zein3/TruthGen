# Specification


## Expression
| exp (expression) | exp {binaryOp exp}*      |
|                  | (exp)                    |
|                  | unaryOp exp              |
|                  | var                      |
|                  | immediate value          |
| immediate value  | 'T' or 'F'               |
| var              | letters (not T or F)     |
| binaryOp         | Refer to Binary Operator |
| unaryOp          | Refer to Unary Operator  |


## Binary Operator
| symbol      | meaning     |
| ---         | ---         |
| ^           | And         |
| &           | And         |
| v           | Or          |
| vetical bar | Or          |
| >           | Implication |
| =           | Equivalence |


## Unary Operator
| symbol | meaning     |
| ---    | ---         |
| !      | Not         |
| ~      | Not         |



## Classes
### Scanner
| function name  | parameters         | output    | note                                                                    |
| ---            | ---                | ---       | ---                                                                     |
| constructor    |                    |           | part of Truth Calculator.                                               |
| loadExpression | expression: string |           |                                                                         |
| advance        |                    |           | go to the next token.                                                   |
| goBack         |                    |           |                                                                         |
| hasMoreTokens  |                    | boolean   |                                                                         |
| tokenType      |                    | TokenType | get type of the token at current index                                  |
| getValue       |                    | boolean   | get value at current index. Only works if current token is VALUE.       |
| getOperator    |                    | Operator  | get operator at current index.                                          |

TokenType = {IMM, UNARYOP, BINARYOP}
Operator = {AND, OR, NOT, IF, EQ}
### Permuter inherit from Variable Table
Description: Permute variables from all true to all false and manages variable.
| function name    | parameters         | output       | note                                                 |
| ---              | ---                | ---          | ---                                                  |
| constructor      | expression: string |              | prepare the variable table.                          |
| getExpression    |                    | string       | the variable has been replaced with values (T or F). |
| permute          |                    |              | go to the next permutation.                          |
| canPermute       |                    | boolean      | returns false if all symbols are false.              |
### Variable Table
| function name    | parameters           | output       | note                                                |
| ---              | ---                  | ---          | ---                                                 |
| constructor      | expression: string   |              | generate table.                                     |
|                  |                      |              | All variables are initialized to true.              |
| getVariables     |                      | vector<char> | get a list of variables in expression.              |
| getVariableValue | var: char            | boolean      | returns false if the variable is not found.         |
| setVariableValue | var: char, val: bool | boolean      | returns true if operation success, false otherwise. |
### Truth Calculator
Description: calculate the result of an expression (can not calculate variables).
| function name  | parameters         | output  | note                                                       |
| ---            | ---                | ---     | ---                                                        |
| constructor    |                    |         | initialize parser.                                         |
| calculateTruth | expression: string | boolean | no variables in expression, only operators and imm values. |
### Truth Generator
Description: Orchestrate the whole process.
