int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

// The main function to convert infix expression
//to postfix expression
void infixToPostfix(string s) {

  stack < char > st;
  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;
    else if (c == '(')
      st.push('(');
    else if (c == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    }

    else {
      while (!st.empty() && prec(s[i]) <= prec(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }
  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  cout << "Prefix expression: " << result << endl;
}

bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
  case '^':
  case '%':
    return true;
  }
  return false;
}

// Convert prefix to Infix expression
string preToInfix(string pre_exp) {
  stack<string> s;

  // length of expression
  int length = pre_exp.size();

  // reading from right to left
  for (int i = length - 1; i >= 0; i--) {

    // check if symbol is operator
    if (isOperator(pre_exp[i])) {

      // pop two operands from stack
      string op1 = s.top();   s.pop();
      string op2 = s.top();   s.pop();

      // concat the operands and operator
      string temp = "(" + op1 + pre_exp[i] + op2 + ")";
// post ti inf and loop from 0th
      //string temp = "(" + op2 + pre_exp[i] + op1 + ")";
      // Push string temp back to stack
      s.push(temp);
    }

    // if symbol is an operand
    else {

      // push the operand to the stack
      s.push(string(1, pre_exp[i]));
    }
  }

  // Stack now contains the Infix expression
  return s.top();
}
// Convert postfix to Prefix  expression
string postToPre(string post_exp)
{
    stack<string> s;
 
    // length of expression
    int length = post_exp.size();
 
    // reading from left to right
    for (int i = 0; i < length; i++) {
 
        // check if symbol is operator
        if (isOperator(post_exp[i])) {
 
            // pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
 
            // concat the operands and operator
            string temp = post_exp[i] + op2 + op1;
 
            // Push string temp back to stack
            s.push(temp);
        }
 
        // if symbol is an operand
        else {
 
            // push the operand to the stack
            s.push(string(1, post_exp[i]));
        }
    }
 
    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    return ans;
}