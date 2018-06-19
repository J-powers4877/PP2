#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 64

int iTop = -1;

char newStack[SIZE];
char userInput[SIZE];


void newPush(int i);
int iPop();
void postfixEvaluation(char* postFix);

int main()
{
    printf("Please input a value: ");
    scanf("%s", userInput);
    postfixEvaluation(userInput);
}

void newPush(int i)
{
    iTop = iTop + 1;
    newStack[iTop] = i;
}

int iPop()
{
    int iFirstItem;
    iFirstItem = newStack[iTop];
    iTop = iTop - 1;
    return iFirstItem;
}


void postfixEvaluation(char* postFix)
{
    char cPostFix;
    int iFirst;
    int iSecond;
    int iValue;
    int iPostFixIterator;

    for (iPostFixIterator = 0; postFix[iPostFixIterator] != '\0'; iPostFixIterator++)
    {
        cPostFix = postFix[iPostFixIterator];
        if (isdigit(cPostFix))
        {
            newPush(cPostFix - '0');
        }
        else if (cPostFix == '+' || cPostFix == '-' || cPostFix == '*' || cPostFix == '/')
        {
            iFirst = iPop();
            iSecond = iPop();

            switch (cPostFix)
            {
                case '*':
                {
                    iValue = iSecond * iFirst;
                    break;
                }
                case '/':
                {
                    iValue = iSecond / iFirst;
                    break;
                }
                case '+':
                {
                    iValue = iSecond + iFirst;
                    break;
                }
                case '-':
                {
                    iValue = iSecond - iFirst;
                    break;
                }
            }

            newPush(iValue);
        }
    }

    printf("\n Result: %d \n", iPop());
}