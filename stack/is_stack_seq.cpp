#include "../helper.hpp"
#include <stack>

using namespace std;

bool isStackSeq(const char *inSeq, const char *outSeq) {
  if (inSeq == NULL && outSeq == NULL) return true;
  if (inSeq == NULL || outSeq == NULL) return false;
  
  stack<char> inStack;
  const char *currentIn = inSeq;
  const char *currentOut = outSeq;
  while(*currentIn != 0) {
    inStack.push(*currentIn);
    while (*currentOut != 0 && inStack.size() > 0 && inStack.top() == *currentOut) {
      inStack.pop();
      currentOut++;
    }
    currentIn++;
  }
  if (*currentIn == 0 && *currentOut == 0 && inStack.size() == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  const char *in = "12345";
  const char *out = "12453";

  cout << isStackSeq(in, out) << endl;
  return 0;
}
