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


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++
//helper function
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++

//return index of first char of targeted char
int checkExist(const char str[],const char target[]){
    for(int i =0;i<countCharacters(str);i++){
        if(str[i]!=target[0]){
            continue;
        }

        int check = 0;
        for(int j=0;j<countCharacters(target);j++){
            if(str[j+i]==target[j]){
                check++;
            }
        }

        if(check==countCharacters(target)){
            return i;
        }
    }

    return -1; //not found
}

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

//to be done
void swapString(char str[], const char target[], const char to[])
{

    //Description - Replaces every instance of the characters in target in str with the characters in to.
    char newStr[MAX_STRLEN];

    int idx = checkExist(str,target);

    int strLength = countCharacters(str);
    int targetLength = countCharacters(target); 

    int shift = countCharacters(to)-targetLength;
    str = newStr;

}
//tested
void encryptText(char str[], int shift)
{   
    while(shift<0){
        shift+=26;
    }
    shift %=26; 

    for(int i=0;i<countCharacters(str);i++){
        char& c = str[i];
        if('a' <= c && c <= 'z'){
            for(int j=0;j<shift;j++){
                c++;
                if(c>'z'){
                    c='a';
                }
            }
        }

       if('A' <= c && c <= 'Z'){
            for(int j=0;j<shift;j++){
                c++;
                if(c>'Z'){
                    c='A';
                }
            }
        }
      
    }
}


//fix
int countNumOccurences(const char str[], const char target[])
{
    int count =0;
    int targetLength = countCharacters(target); //"test"

    int start = checkExist(str,target); //first index
    if(start<0){
        return 0;
    }


    for(int i =start;i<countCharacters(str);){ //skip found letter
        if(checkExist(str+i,target)<0){
            break;
        }else{
            i=checkExist(str+i,target);
            count++;
        }
    }

    return count;
}

void convertIntoLines(const char str[], char lines[MAX_LINES][NUM_CHARS_PER_LINE])
{
    int* wordlength = new int[countWords(str)];

    int count =0;
    int word =0;

    for(int i=0;i<countCharacters(str)+1;i++){
        if(str[i]==' '||str[i]=='\0'){
            wordlength[word] = count;

            cout<<count<< " " ;
            count = 0;

            word++;
            continue;
        }
        count++;
    }  
    //we now have int array of word length (sep by spaces)


    //change array to 
    int count_index=0;
    int line=0;

    int * cut_index = new int[countWords(str)];
    for(int i=0;i<countCharacters(str)+1;i++){
        int currentlengthcount =0;

        for(int j=0;j<countWords(str)-1;j++){//j+1 is for space , +1 is for '\0'
            if(wordlength[j]+wordlength[j+1]+j+1+1<=NUM_CHARS_PER_LINE){
                currentlengthcount=wordlength[j]+wordlength[j+1]+j+1+1;
            }else{
                cut_index[count_index] = currentlengthcount;
                cout<<currentlengthcount;
                count_index++;
            }
        }

        for(int j=0;j<currentlengthcount;j++){//j+1 is for space , +1 is for '\0'
            if(j==currentlengthcount-1){
                lines[line][j] ='\0';
            }
            else{
                lines[line][j] = str[i];
            }
        }
        line++;
    }

    
    delete[] wordlength;
}

void printLeftJustified(const char str[])
{   
    char lines[MAX_LINES][NUM_CHARS_PER_LINE];

    convertIntoLines(str,lines);
    for(int i=0;i<MAX_LINES;i++){
        cout<<lines[i];
    }

    
    
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

    char lines[MAX_LINES][NUM_CHARS_PER_LINE];
    char test [MAX_STRLEN]="Why have a ballroom with no balls.";
    convertIntoLines(test,lines);

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
