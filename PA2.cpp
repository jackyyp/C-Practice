#include <iostream>
#include <climits>
#include <cstdio>

using namespace std;

const int MAX_STRLEN = 1000;
const int NUM_CHARS_PER_LINE = 50;
const int MAX_LINES = 15;

int countCharacters(const char str[]);
int countWords(const char str[]);
int countNumOccurences(const char str[], const char target[]);

void swapString(char str[], const char target[], const char to[]);
void encryptText(char str[], int shift);

void convertIntoLines(const char str[], char lines[MAX_LINES][NUM_CHARS_PER_LINE]);
void printRightJustified(const char str[]);
void printLeftJustified(const char str[]);

void convertStrToPigLatin(char word[]);
void printPigLatin(const char str[]);

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++
// You codes start here. Please do not modify codes above
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++

//tested ,(including space char)
int countCharacters(const char str[])
{
    int length=0;

    while(str[length]!='\0'){
        length++;
    }

    return length; 
    
}

//tested
int countWords(const char str[])
{
    int space=0;
    int i =0;
    while(str[i]!='\0'){
        if(str[i]==' '){ // how about (' ',' ','\0')?  (0 word)
            if(str[i+1]==' ' ||str[i+1]=='\0'){
                space--;
            }
            space++;
        }
        i++;
    }
    return space+1; // Replace this line with your implementation
    //* how about empty string ' ' ? --> *FIX (not returning 1)
}

void swapString(char str[], const char target[], const char to[])
{
    int newCount = 0;

    newCount = countCharacters(str)-countCharacters(target)+countCharacters(to);
    char newSentence[newCount+1]; //null char , to store the new sentence

    int targetStartIndex=0,targetEndIndex=0; // **TBC
    int word_index[countWords(str)]; //storing the starting index of each word

    int count=0;
    for(int i=0;i<countCharacters(str);i++){
        if(str[i]==' '){
            word_index[count] = i+1; //idx
            count++;
        }
    }
    //

}

void encryptText(char str[], int shift)
{   
    shift %= 26;
    if(shift<0){
        shift +=26; // revert shift dir
    }

    int i =0;
    while(str[i]!='\0'){
           if(('a' <= str[i] && str[i] <= 'z' )||('A' <= str[i] && str[i] <= 'Z' ) ){
                str[i]+=shift;
                if(str[i]>'z'){
                    str[i]-='a';
                }
           }
           i++;
    }


    for(int i =0;str[i]!='\0';i++){
        cout<< str[i];
    }

    
    
    
}

int countNumOccurences(const char str[], const char target[])
{
    return -1; // Replace this line with your implementation
}

void convertIntoLines(const char str[], char lines[MAX_LINES][NUM_CHARS_PER_LINE])
{
    cout << "Not Implemented" << endl; // Replace this line with your implementation
}

void printLeftJustified(const char str[])
{
    cout << "Not Implemented" << endl; // Replace this line with your implementation
}

void printRightJustified(const char str[])
{
    cout << "Not Implemented" << endl; // Replace this line with your implementation
}

void printJustified(const char str[])
{
    cout << "Not Implemented" << endl; // Replace this line with your implementation
}

void convertStrToPigLatin(char str[])
{
    cout << "Not Implemented" << endl; // Replace this line with your implementation
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++
// You codes end here. Please do not modify codes below
// ++++++++++++++++++++++++++++++++++++++++++++++++++++

void printPigLatin(const char str[])
{
    char pigLatin[MAX_STRLEN];
    for (int i = 0; i < MAX_STRLEN; ++i)
    {
        pigLatin[i] = str[i];
    }
    convertStrToPigLatin(pigLatin);
    int strLen = countCharacters(pigLatin);
    for (int i = 0; i < strLen; ++i)
    {
        if (pigLatin[i] >= 'A' && pigLatin[i] <= 'Z')
        {
            pigLatin[i] = 'a' + pigLatin[i] - 'A';
        }
    }
    cout << pigLatin << endl;
}

void printMainDisplay(const char str[])
{
    cout << str << endl
         << "===================================\n"
         << "1. Character Count\n"
         << "2. Word Count\n"
         << "3. Encrypt (Caeser Cipher)\n"
         << "4. Find and Replace String Globally\n"
         << "5. Find Frequency of String\n"
         << "6. Print Left Align Text\n"
         << "7. Print Right Align Text\n"
         << "8. Print Left-Right Align Text\n"
         << "9. Print Pig Latin\n"
         << "Please make your choice: ";
}

int main()
{
    int choice = 0;
    char str[MAX_STRLEN];

    cout << "Enter text: ";
    cin.getline(str, MAX_STRLEN, '\n');

    do
    {
        printMainDisplay(str);
        cin >> choice;
    } while (choice < 1 || choice > 9);

    if (choice == 1)
    {
        cout << "Total character count: " << countCharacters(str) << endl;
    }
    else if (choice == 2)
    {
        cout << "Total word count: " << countWords(str) << endl;
    }
    else if (choice == 3)
    {
        cout << "Enter the shift amount for the caeser cipher encryption (rotation encryption): ";
        int shift;
        cin >> shift;
        encryptText(str, shift);
        cout << str << endl;
    }
    else if (choice == 4)
    {
        cout << "Enter the string to find and replace: ";
        char target[MAX_STRLEN];
        cin.ignore(INT_MAX, '\n');
        cin.getline(target, MAX_STRLEN, '\n');

        cout << "Enter the string to replace it with: ";
        char to[MAX_STRLEN];
        cin.getline(to, MAX_STRLEN, '\n');

        swapString(str, target, to);
        cout << str << endl;
    }
    else if (choice == 5)
    {
        cout << "Enter the string to count the occurences of: ";
        char target[MAX_STRLEN];
        cin.ignore(INT_MAX, '\n');
        cin.getline(target, MAX_STRLEN, '\n');

        cout << '"' << target << '"' << " appears in the text " << countNumOccurences(str, target) << " time(s).\n";
    }
    else if (choice == 6)
    {
        printLeftJustified(str);
    }
    else if (choice == 7)
    {
        printRightJustified(str);
    }
    else if (choice == 8)
    {
        printJustified(str);
    }
    else if (choice == 9)
    {
        printPigLatin(str);
    }
}
