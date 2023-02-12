#include <iostream>
#include <climits>
#include <cstdio>

using namespace std;

const int MAX_STRLEN = 1000;
const int NUM_CHARS_PER_LINE = 10; // mutated
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

bool checkVowel(const char letter){

    char vowel[] = {'a','e','i','o','u'};

    for(int i =0;i<5;i++){
        if(letter==vowel[i]){
            return true;
        }
    }

    return false;
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

    int targetLength = countCharacters(target);
    int strLength = countCharacters(str);
    int toLength = countCharacters(to);
    
    int strBegin = checkExist(str,target); // " .. testing_" we get start = 0, end = 7 (the empty space)
    int strEnd = strBegin+targetLength;
    
    

    do
    {
    int k = 0;
    for(int i=0;i<strBegin;i++){
        newStr[k] = str[i];
        k++; 
    }
    for(int i=0;i<toLength;i++){
        newStr[k] = to[i];
        k++;
    }
    for(int i=0;i<strLength-strEnd;i++){
        newStr[k]=str[strEnd+i];
        k++;
    }
    
    newStr[k]='\0';
    }
    while(false);

    cout<<newStr<<endl;

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


//fixed
int countNumOccurences(const char str[], const char target[])
{
    int count =0;
    int targetLength = countCharacters(target); //"test"
    int strLength = countCharacters(str);

    for (int i =0;i<strLength-targetLength;i++){ //slide one by one
        int j=0; 
        for(;j<targetLength;j++){
            if(str[i+j]!=target[j]){
                break;
            }
        }

        if(j==targetLength){
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

            count = 0;

            word++;
            continue;
        }
        count++;
    }  

    //we now have int array of word length (sep by spaces)
    
    int linelength[MAX_LINES];

    int idx = 0;
    int acc=0;
    int linecount=0;

    cout<<endl;

    while(idx < countWords(str)){
        if(acc+wordlength[idx] <= NUM_CHARS_PER_LINE-1){
            acc+=wordlength[idx];
            acc++; //space 

            if(idx == countWords(str)-1){ //last word
                linelength[linecount]=acc;
              
                linecount++;
                break;
            }
           
            idx++; //next word          


        }else{ //exceed
            linelength[linecount]=acc;
           
            linecount++;
            acc=0;
        }
    }

    //now we have a list of length for each line

    int k=0; //itr for str    
    for(int line=0;line<linecount;line++){
        for(int i=0;i<linelength[line]-1;i++){
            if(str[k]==' '&&i==0){
                k++;
            }
            lines[line][i]=str[k];
            k++;
        }
        lines[line][linelength[line]-1]='\0';
    }

    delete[] wordlength;

}

void printLeftJustified(const char str[])
{   
    char lines[MAX_LINES][NUM_CHARS_PER_LINE];
    convertIntoLines(str,lines);

    int* wordlength = new int[countWords(str)];
    int count =0;
    int word =0;

    for(int i=0;i<countCharacters(str)+1;i++){
        if(str[i]==' '||str[i]=='\0'){
            wordlength[word] = count;

            count = 0;

            word++;
            continue;
        }
        count++;
    }  

    //we now have int array of word length (sep by spaces)
    
    int linelength[MAX_LINES];

    int idx = 0;
    int acc=0;
    int linecount=0;

    cout<<endl;

    while(idx < countWords(str)){
        if(acc+wordlength[idx] <= NUM_CHARS_PER_LINE-1){
            acc+=wordlength[idx];
            acc++; //space 

            if(idx == countWords(str)-1){ //last word
                linelength[linecount]=acc;
              
                linecount++;
                break;
            }
           
            idx++; //next word          


        }else{ //exceed
            linelength[linecount]=acc;
           
            linecount++;
            acc=0;
        }
    }

    //now we have a list of length for each line

    for(int i=0;i<linecount;i++){
        cout<<lines[i]<<endl;
    }

    
    
}

void printRightJustified(const char str[])
{
    char lines[MAX_LINES][NUM_CHARS_PER_LINE];
    convertIntoLines(str,lines);

    int* wordlength = new int[countWords(str)];
    int count =0;
    int word =0;

    for(int i=0;i<countCharacters(str)+1;i++){
        if(str[i]==' '||str[i]=='\0'){
            wordlength[word] = count;

            count = 0;

            word++;
            continue;
        }
        count++;
    }  

    //we now have int array of word length (sep by spaces)
    
    int linelength[MAX_LINES];

    int idx = 0;
    int acc=0;
    int linecount=0;

    cout<<endl;

    while(idx < countWords(str)){
        if(acc+wordlength[idx] <= NUM_CHARS_PER_LINE-1){
            acc+=wordlength[idx];
            acc++; //space 

            if(idx == countWords(str)-1){ //last word
                linelength[linecount]=acc;
              
                linecount++;
                break;
            }
           
            idx++; //next word          


        }else{ //exceed
            linelength[linecount]=acc;
           
            linecount++;
            acc=0;
        }
    }

    //now we have a list of length for each line

    for(int i =0;i<linecount;i++){
        for(int j=0;j<NUM_CHARS_PER_LINE-linelength[i];j++){
            cout<<" ";
        }
        cout<<lines[i]<<endl;
    }
}

void printJustified(const char str[])
{
    cout << "Not Implemented" << endl; // Replace this line with your implementation
}

void convertStrToPigLatin(char str[])
{
    //create a 2d array of words
    char** word = new char* [countWords(str)];
    for(int i=0;i<countWords(str);i++){
        word[i] = new char[MAX_STRLEN]; 
    }

    int strLen = countCharacters(str);

    int wordStartIdx = 0;
    for(int k=0;k<countWords(str);k++){
        for(int i=wordStartIdx;i<=strLen;i++){
            if(str[i]==' '||str[i]=='\0'){
                wordStartIdx = i+1;
                word[k][i] = '\0';
                break;
            }
            word[k][i] = str[i];
        }   
    }

    for(int i=0;i<countWords(str);i++){
        cout<< word[i]<<endl;
    }    


    cout<<endl;


   //maniputlate the array
    for(int i=0;i<countWords(str);i++){
        int endIdx = 0;

        for(int j=0;j<MAX_STRLEN;j++){
            if(word[i][j] =='\0'){
                break;
            }
            endIdx++;
        }

        //already vowel
        if(checkVowel(word[i][0])){
            word[i][endIdx] = 'y';
            word[i][endIdx+1] = 'a';
            word[i][endIdx+2] = 'y';
            word[i][endIdx+3] = '\0';
            continue;
        }

        //not already vowel , shift
        while(!checkVowel(word[i][0])){
            word[i][endIdx] = word[i][0];
            word[i][endIdx+1] = '\0';

            //left shift
            for(int j=0;j<endIdx+1;j++){
                word[i][j] = word[i][j+1];
            }
        }

        word[i][endIdx] = 'a';
        word[i][endIdx+1] = 'y';
        word[i][endIdx+2] = '\0';
        
   }
   
    //print the word
   for(int i=0;i<countWords(str);i++){
     cout<< word[i] <<endl;
   }



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
    convertStrToPigLatin(test);

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
