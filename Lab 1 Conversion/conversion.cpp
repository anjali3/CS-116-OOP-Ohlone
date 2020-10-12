/*
Anjali Patel (CS-116 Lab 1)
Monday morning 8 am with Professor Ron Sha.
In this unit conversion lab the program converts from seconds to hours and minutes,
Fahrenheit to Celsius and Celsius to Fahrenheit. The user has the option to select
which unit types they want to be converted. Each selection has its own function.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cmath>


using namespace std;

//function declaration
void printMeFirst(string name, string courseInfo);
void select();
void fToc();
void secondsConversion();
void cTof();

//In this main function other functions are being called when the program executes.
int main()
{
	printMeFirst("Anjali Patel","CS-116 Lab 1:Conversion"); // pass your name, your class info to function so it will print them out.
    select();
    
}

/* Print out the programmer’s information such as name, class information
and date/time the program is run
    
     @param name - the name of the programmer
     @param courseInfo - the name of the course
     @return - none
*/

//This function contains programmer's information that prints out in beginning of the program    
void printMeFirst(string name, string courseInfo)
{
    cout <<"Program written by: "<< name << endl; // put your name here
    cout <<"Course info: "<< courseInfo << endl;
    time_t now = time(0); // current date/time based on current system
    char* dt = ctime(&now); // convert now to string for
    cout << "Date: " << dt << endl;
}



    
//This function converts seconds int minutes, hours and seconds.
void secondsConversion()
{
    int seconds, minutes, hours;
    cout << "Enter in the number of seconds: " << endl; //Asks the user to enter a number of seconds.
    while (1)
    {
        if (cin >> seconds && seconds >= 0) //Takes in the seconds value and checks if it is a valid positive number.
        {
            break; //If it is valid with the if statement above, this breaks the loop of invalid input.
        }
        else //Error will keep on printing if random letters are entered in.
        {
            cout << "Invalid Input! Please input a numerical value." << endl;
            cin.clear(); //Allows user to reenter the seconds
            while (cin.get() != '\n') ;
        }
    
    }
    
     minutes = seconds / 60; //Formulas for conversion.
     hours = minutes / 60;
     cout << seconds << " seconds is: " << int(hours) << " hours, " << int(minutes%60) << " minutes, " << int(seconds%60) << " seconds " << endl; //Displays result
}
    
//This function converts the temperature from Fahrenheit to Celsius.
void fToC()
{
    float f = 0.0, c = 0.0;
    cout << "Enter a Fahrenheit value: ";
    
    while (1)
     {
        if (cin >> f) //Takes in the Fahrenheit value and checks if it is a valid number
        {
            break; //If it is valid with the if statement above, this breaks the loop of invalid input.
        }
        else
        {
            cout << "Invalid Input! Please input a numerical value." << endl;

            cin.clear(); //Allows user to reenter the Fahrenheit.
            while (cin.get() != '\n') ;
            
        }
    }
     c = ((f-32.0)*(5.0/9.0)); //Formulas for conversion.
     cout <<  f << " F is equal to " << fixed << setprecision(1) << c << " C " << endl; //Displays result
}
    
//This function converts the temperature from Celsius to Fahrenheit.
void cToF()
{
    double c, f;
    cout << "Enter a Celsius value: ";
    while (1) {
    if (cin >> c) //Takes in the Celsius value and checks if it is a valid number
    {
        break; //If it is valid with the if statement above, this breaks the loop of invalid input.
    }
    else
    {
        cout << "Invalid Input! Please input a numerical value." << endl;
        cin.clear(); //Allows user to reenter the Celsius.
        while (cin.get() != '\n') ;
        
        }
    }
    
     f = c*(9.0/5.0) + 32.0; //Formulas for conversion.
     cout << c << " C is equal to " << f << " F " << endl; //Displays result
    

}
/*This function has the selection menu with cin.fail() condition in do-while loop. The selection menu gives user
 * choice on what unit conversion they want to use. When the program is executed the first thing that is printed 
 * is the printMeFirst function and then this function. This function will show the 4 options user has. This function
 * is called in int main() function.*/
void select()
{
    int selection;
    do
    {
        cout << "Choose a selection below:" << endl;
        cout << "\t1 - Seconds to hours, minutes and seconds" << endl;
        cout << "\t2 - Fahrenheit to Celsius" << endl;
        cout << "\t3 - Celsius to Fahrenheit" << endl;
        cout << "\t4 - Quit" << endl;
        cin >> selection; //User inputs their selection
	
        while(cin.fail())
        {
            cout << "Invalid selection! Please try again" << endl;
            cin.clear(); //Allows user to reenter the conversion they want to convert.
            cin.ignore();
			while (cin.get() != '\n') ;
            select();
        }
            //This selection goes to Seconds Conversion.
            if(selection == 1)
            {    
                secondsConversion();
            }
            //This selection goes to Fahrenheit to Celsius Conversion.
            else if(selection == 2)
            {
                
                fToC();
            }
            //This selection goes to Celsius to Fahrenheit Conversion.
            else if(selection == 3)
            {
                cToF();
            }
            //This selection quits the program with a closing greeting.
            else if(selection == 4)
            {
				cout << "Thank You for using my program! Have a great day!" << endl;
				
            }
            //This statement gets printed if user selects an invalid input.    
            else
            {
				
                cout << "Please enter in a valid selection" << endl;
                
            }
    }while (selection != 4); //This quits out the program when user selects quit
}


	
