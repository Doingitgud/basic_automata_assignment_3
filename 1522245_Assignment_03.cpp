#include<iostream>
using namespace std;
int findingStringLength(string a);
void findingCharacterInString(string a, char c);
int *findingSubStringInString(string a, string b, int &arrayCounter);
void findingPrefixSuffixInString(string dd, string ee);
string reverseStringOperation(string a);
string concatenation(string a,string b);
bool stringEqualityChecker(string aa, string bb);
void checkConceptOfString(string w, string x);
void partitionString(string a);
int main()
{
    cout<<"Press 1 to view solution to question 1"<<endl;
    cout<<"Press 2 to view solution to question 2"<<endl;
    cout<<"Press 3 to view solution to question 3"<<endl;
    cout<<"Press 4 to view solution to question 4"<<endl;
    cout<<"Press 5 to view solution to question 5"<<endl;
    cout<<"Press 6 to view solution to question 6"<<endl;
    cout<<"Press 7 to view solution to question 7"<<endl;
    cout<<"Press 8 to view solution to question 8"<<endl;
    cout<<"Press p to view solution to question partition function"<<endl;
    char selection;
    cin>>selection;
//-------------------------------------------------------------------------------------
    if(selection=='1')
    {

        string a="";
        cout<<"Please input a string : "<<endl;
        cin>>a;
        cout<<"Length of the string is : "<<findingStringLength(a)<<endl;
    }

//----------------------------------------------------------------------------------------
    else if(selection=='2')
    {
        string b="";
        char c='\0';
        cout<<"Please input a string : "<<endl;
        cin>>b;
        cout<<"Please input the search character : "<<endl;
        cin>>c;
        findingCharacterInString(b,c);
    }

//-------------------------------------------------------------------------------------------------------------------------------------------------------
    else if(selection=='3')
    {
        string d="",e="";
        int *locationSubstring, arrayCounter=0;
        cout<<"Please input a string : "<<endl;
        cin>>d;
        cout<<"Please input a string to check substring : "<<endl;
        cin>>e;
        locationSubstring=findingSubStringInString(d,e,arrayCounter);

        if(arrayCounter>0)
        {
            cout<<"Substring exists. ";
            cout<<"It occurs "<<arrayCounter<<" times at position ";
            for(int l=0; l<arrayCounter; l++)
            {
                if(l==arrayCounter-2)
                {
                    cout<<locationSubstring[l]<<" and ";
                }
                else if(l==arrayCounter-1)
                {
                    cout<<locationSubstring[l]<<" in the string."<<endl;
                }
                else
                {
                    cout<<locationSubstring[l]<<", ";
                }
            }
        }
        else
        {
            cout<<"Substring does not exist.";
        }
    }

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
    else if(selection=='4')
    {
        string dd="",ee="";
        cout<<"Please input a string : "<<endl;
        cin>>dd;
        cout<<"Please input a string to check whether substring is a prefix, suffix or both  : "<<endl;
        cin>>ee;
        findingPrefixSuffixInString(dd,ee);
    }
//------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if(selection=='5')
    {
        string s="", t="";
        cout<<"Please input string s : "<<endl;
        cin>>s;
        cout<<"Please input string t : "<<endl;
        cin>>t;
        cout<<"Concatenation of the input strings, st = "<<concatenation(s,t)<<endl;
    }
//------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if(selection=='6')
    {
        string gg="";
        cout<<"Please input a string : "<<endl;
        cin>>gg;
        cout<<"Reverse of the input string : \n"<<reverseStringOperation(gg)<<endl;

    }
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if(selection=='7')
    {
        string aa="", bb="";
        cout<<"Please input your first string : "<<endl;
        cin>>aa;
        cout<<"Please input your second string to check for equality : "<<endl;
        cin>>bb;
        if(stringEqualityChecker(aa,bb))
        {
            cout<<"Strings are equal\n";
        }
        else
        {
            cout<<"Strings are not equal\n";
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if(selection=='8')
    {
        string w="",x="";
        cout<<"Please input string w : "<<endl;
        cin>>w;
        cout<<"Please input string v : "<<endl;
        cin>>x;
        checkConceptOfString(w,x);
    }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if(selection=='p')
    {
        string pp="";
        cout<<"Please input a string :\n";
        cin>>pp;
        partitionString(pp);
    }
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
    else
    {
        cout<<"\nIncorrect input please try again. "<<endl;
    }

    return 0;
}
int findingStringLength(string a)
{
    int i=0;
    while(a[i]!=NULL)
    {
        i++;
    }
    return i;
}
void findingCharacterInString(string b, char c)
{
    int j=0, counterb=0;
    j=findingStringLength(b);
    int *location=new int[j];
    for(int l=0; l<j; l++)
    {
        location[l]=-1;
    }
    for(int l=0; l<j; l++)
    {
        if(b[l]==c)
        {
            location[counterb]=l;
            counterb++;
        }
    }
    if(counterb>0)
    {
        cout<<"Character occurs "<<counterb<<" times at position ";
        for(int l=0; l<counterb; l++)
        {
            if(l==counterb-2)
            {
                cout<<location[l]<<" and ";
            }
            else if(l==counterb-1)
            {
                cout<<location[l]<<" in the string."<<endl;
            }
            else
            {
                cout<<location[l]<<", ";
            }
        }
    }
    else
    {
        cout<<"Character does not occur in the string "<<endl;
    }
}
int *findingSubStringInString(string a, string b,int &arrayCounter)
{
    int k=0, l=0, checkValue;
    char previous='\0';
    k=findingStringLength(a);
    l=findingStringLength(b);
    int *location=new int[k];
    for(int i=0; i<k; i++)
    {
        location[i]=-1;
    }
    if(l>k)
    {
        cout<<"The input substring length cannot be greater than input string length.\n";
        arrayCounter=0;
        return location;
    }
    else
    {
        for(int i=0; i<=k-l; i++)
        {
            for(int j=i; j<i+l; j++)
            {
                checkValue=1;
                if (a[j]!=b[j-i])
                {
                    checkValue=0;
                    break;
                }
            }
            if (checkValue==1)
            {
                location[arrayCounter]=i;
                arrayCounter++;

            }
        }
        return location;
    }
}
void findingPrefixSuffixInString(string dd, string ee)
{
    int m=0, n=0;
    int *locationSubstringPrefSuff, arrayCounterPrefSuff=0;
    bool checkPrefix=false, checkSuffix=false;
    m=findingStringLength(dd);
    n=findingStringLength(ee);
    locationSubstringPrefSuff=findingSubStringInString(dd, ee, arrayCounterPrefSuff);
    if(arrayCounterPrefSuff>0)
    {
        for(int i=0; i<arrayCounterPrefSuff; i++)
        {
            if(locationSubstringPrefSuff[i]==0)
            {
                checkPrefix=true;
            }
            if(locationSubstringPrefSuff[i]==m-n)
            {
                checkSuffix=true;
            }
        }
        if(checkPrefix&&checkSuffix)
        {
            cout<<"The input substring is a prefix and a suffix.\n";
        }
        else if(checkPrefix)
        {
            cout<<"The input substring is a prefix.\n";
        }
        else if(checkSuffix)
        {
            cout<<"The input substring is a suffix.\n";
        }
        else
        {
            cout<<"Input substring is not a prefix and a suffix.\n";
        }
    }
    else
    {
        cout<<"Input check-string is not a substring of the input string\n";
    }
}
string concatenation(string a,string b)
{
    string hhh="";
    hhh=a+b;
    return hhh;
}
string reverseStringOperation(string a)
{
    string f="";
    int m=0;
    char temp='\0';
    f=a;
    m=findingStringLength(a);
    for(int i=0; i<m/2; i++)
    {
        temp=f[i];
        f[i]=f[m-1-i];
        f[m-1-i]=temp;
    }
    return f;
}
bool stringEqualityChecker(string aa,string bb)
{
    int n=0, o=0, counteraa=0, counterbb=0;
    n=findingStringLength(aa);
    o=findingStringLength(bb);
    if(n==o)
    {
        for(int i=0; i<n; i++)
        {
            if(aa[i]==bb[i])
            {
                counterbb++;
            }
            counteraa++;
        }
        if(counterbb==counteraa)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
void checkConceptOfString(string w, string x)
{
    int ss=0, tt=0;
    string reverseOfw="", reverseOfx="", concatenationOfwx="", reverseConcatenationOfwx="", individualReverseConcatxw="";
    ss=findingStringLength(w);
    tt=findingStringLength(x);
    concatenationOfwx=concatenation(w,x);
    reverseConcatenationOfwx=reverseStringOperation(concatenationOfwx);
    cout<<"Input string w = "<<w<<endl;
    cout<<"Input string x = "<<x<<endl;
    cout<<"Concatenation of string w and x, wx = "<<concatenationOfwx<<endl;
    cout<<"Reverse of the concatenation wx, (wx)R = "<<reverseConcatenationOfwx<<endl;
    reverseOfw=reverseStringOperation(w);
    reverseOfx=reverseStringOperation(x);
    individualReverseConcatxw=concatenation(reverseOfx,reverseOfw);
    cout<<"Reverse of string w, wR : "<<reverseOfw<<endl;
    cout<<"Reverse of string x, xR : "<<reverseOfx<<endl;
    cout<<"Concatenation of wR and xR, (xR)+(wR) = "<<individualReverseConcatxw<<endl;
    if(stringEqualityChecker(reverseConcatenationOfwx,individualReverseConcatxw))
    {
        cout<<"\nStrings (wx)R and (xR)+(wR) are equal, (wx)R = (xR)+(wR)\n";
    }
    else
    {
        cout<<"\nStrings are not equal\n";
    }

}
void partitionString(string a)
{
    int z=0;
    string cutString="", otherPart="", concatenationString="", reverseConcatenation="", reverseOfLeft="", reverseOfRight="",individualReverseConcat="";
    int i,j,k;
    z=findingStringLength(a);
    for(i=0; i<z; i++)
    {
        for(j=0; j<=i; j++)
        {
            cutString+=a[j];
        }
        for(k=i+1; k<z; k++)
        {
            otherPart+=a[k];
        }
        cout<<"left part of input string, Left : "<<cutString<<endl;
        cout<<"right part of input string, Right : "<<otherPart<<endl;
        concatenationString=concatenation(cutString,otherPart);
        reverseConcatenation=reverseStringOperation(concatenationString);
        cout<<"Concatenation of left and right strings, Left+Right : "<<concatenationString<<endl;
        cout<<"Reverse of this concatenation, (Left+Right)R : "<<reverseConcatenation<<endl;
        reverseOfLeft=reverseStringOperation(cutString);
        reverseOfRight=reverseStringOperation(otherPart);
        individualReverseConcat=concatenation(reverseOfRight,reverseOfLeft);
        cout<<"Reverse of left string, (Left)R : "<<reverseOfLeft<<endl;
        cout<<"Reverse of right string, (Right)R : "<<reverseOfRight<<endl;
        cout<<"Concatenation of (Right)R+(Left)R = "<<individualReverseConcat<<endl;
        if(stringEqualityChecker(reverseConcatenation,individualReverseConcat))
        {
            cout<<"\nStrings (LeftRight)R and (Right)R+(Left)R are equal, (LeftRight)R = (Right)R+(Left)R\n";
        }
        else
        {
            cout<<"\nStrings are not equal\n";
        }
        cout<<"\n\n\n\n\n";
        cutString="";
        otherPart="";
    }


}
