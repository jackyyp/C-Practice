// Use basic variables in C++, like int, char, bool, etc.
// Use if, if-else, switch statements to control program flow
// Use relational operators and logical operators to control program flow.
// Use for, while, and do-while to write loops, as well as use break and continue to exit loops.


#include <iostream>
using namespace std;

//global variable
    const char* months[] = {"January","February","March","April","May","June",
    "July","August","September",
    "October","November","December"}; 
        
    const char* weekdays[] = {"We","Th","Fr","Sa","Su","Mo","Tu","We","Th","Fr","Sa","Su"};

    int monthDay[]  ={31,28,31,30,31,30,31,31,30,31,30,31};



int calculate_weekday(const int year,const int month);
void print_horizontally(const int year,const int month);
void print_vertically(const int year,const int month);
void print_year(const int year);
void print_year_row(const int year,const int current_month);


void print_year_row(const int year,const int current_month){

    int shift=3; //sun

    //print 3 consecutive month first;
        for(int i =0;i<3;i++){
            cout<<months[current_month+i]<<" "<<" ";
        }
        cout<<endl;

        for(int i=0;i<3;i++){
            for(int j =0;j<7;j++){
                cout<< weekdays[j+(7-shift)]<<" ";
            }
            cout<< " "<<" ";
        }
        cout<<endl;

        for(int i=0;i<3;i++){
            int firstDay = (calculate_weekday(year,current_month+i)+shift)%7;
        }

        cout<<endl;

};

void print_year(const int year){
    cout<<"Year "<<year<<endl;

    int shift=3; //sun

    //print 3 consecutive month first;

    

}

int calculate_weekday(const int year,const int month){
    int firstDay=0;

    for(int i=0;i<month;i++){
        firstDay += monthDay[i];
    }

    firstDay += (year-1800)*365;
    firstDay %= 7; 

    return firstDay;
    
};

//we have wed=0 , tue =6;

//to be fixed (hardcoding)
//memo: storing array wrt weekday; 


void print_horizontally(const int year,const int month,const char start){ //sun
    int shift=0; // 3 if sun,2 if mon

    
    if(start=='s'){
        shift=3;
    }else{
        shift=2;
    }

    int firstDay = (calculate_weekday(year,month)+shift)%7;


    cout << months[month] <<" "<<year<<endl;

    int totalDay = monthDay[month];
    for(int i =0;i<7;i++){

        cout<< weekdays[i+(7-shift)]<<" ";
    }
    cout<<endl;

  

    for(int i =0;i<firstDay;i++){
        cout<<" "<<" "<<" ";
    }
    
    for(int i =1;i<totalDay+1;i++){ // 1to31
        if(i<10){
            cout<<" "; 
        }
        cout << i << " ";
        if((i+firstDay)%7==0){
            cout <<endl;
        }
    }
};

//the January 1st of year 1800 is a Wednesday.
//Actually you only need to figure out how many days are there in each month.
// day0=wed, day7 = wed; (day%7) == weekday

void print_vertically(const int year,const int month,const char start){
    int shift=0; // 3 if sun,2 if mon
    if(start=='s'){
        shift=3;
    }else{
        shift=2;   
    }

    int firstDay = (calculate_weekday(year,month)+shift)%7;

    cout << months[month] <<" " <<year<<endl;

    int totalDay = monthDay[month];

    int count =0;
    const int MAXDATE = monthDay[month];
   for(int i =0;i<7;i++){
        cout<< weekdays[i+(7-shift)]<<" ";

        if(count<firstDay){
            cout<<" "<<" "<<" ";
            count++;
        }

        int startdate = (7-firstDay+1+i)%7;
        if(startdate==0){
            startdate=7;
        }

        while(startdate<=MAXDATE){
            if(startdate<10){
                cout<<" ";
            }
            cout<< startdate<<" ";

            startdate+=7;
        }
        cout<<endl;
    }


}

int main(){
    int year = 0;
    int month = -5;
    char orientation ;
    char firstDay ;

    // test input 
    // For example, if we want an integer, you can assume 
    // the user will always input an integer, not a character, etc.

    // while(year<1800 || year>9999){
    //     cout << "Enter year (in range 1800-9999): ";
    //     cin >> year;
    // }

    // while(month<0||month>11){
    //     cout << "Enter month (in range 1-12): ";
    //     cin >> month;
    //     month-=1;
    // }


    // while(firstDay != 's' && firstDay != 'm'){
    //     cout<< "Enter the first day of week ('s' for Sunday, 'm' for Monday): ";
    //     cin >> firstDay ;
    // }

    // while(orientation !='h' && orientation!='v'){
    //     cout << "Print horizontally (h) or vertically (v): "; 
    //     cin >> orientation;
    // }


    //the January 1st of year 1800 is a Wednesday (0)
    //storing date in array wrt weekday;


    // cout<< calculate_weekday(1800,1); //feb


   print_year_row(1800,0);
    cout<<endl;
   




    return 0;
}
