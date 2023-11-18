#include<iostream>
#include<iomanip>// iomanip is included to set precision
#include<limits> // limits is included to limit the user input to integer
#include<fstream>// to save the user data in a file

// Formats are defined
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define CLOSEFORMAT "\033[0m"

using namespace std;

class Diet
{
    private:
        // Units for BMI
        float  height,
               height_in_meters,
               weight,
               weight_in_kg;
        // user choices are declared
        int ch1, ch2;
        char ch3;
        // string variable is declared for file name
        string your_name;

    public:
        // Global declaration - for user choice and to store the bmi value
        int choice;
        float bmi;

    // Functions
    void save();
    void calculate();
    void workout();
    void nutrition();
    void faqs();
};




// Main Program
int main()
{
    Diet plan; // Object is declared
    while (plan.choice>0 || plan.choice <7)
    {
        cout<<"\n\n---------------------------------------------------------------";
        cout<<BOLD<<"\n\n\t\t\tDIET PLANNER\n"<<CLOSEFORMAT;
        cout<<"\n---------------------------------------------------------------";
        // Main Menu
        cout<<"\n\n 1. PLAN YOUR DIET\n\n 2. KNOW YOUR BMI CATEGORY\n\n 3. DISPLAY WORKOUT PLANS FOR YOUR BMI\n\n 4. DISPLAY DIET PLANS FOR YOUR BMI\n\n 5. FAQs\n\n 6. EXIT\n";
        cout<< ITALIC <<"\nEnter your choice: ";
        while(!(cin >> plan.choice)) // using while loop - to accept int as input
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ITALIC << "\n--- Invalid input! ---\n\n" << "Enter your choice: ";
            }
        cout<<CLOSEFORMAT;

        switch(plan.choice)
        {
            case 1:
            {
                cout<<"\n---------------------------------------------------------------";
                cout<< BOLD <<"\n\n\t\tKNOW YOUR BMI, WORKOUT & DIET PLANS\n" << CLOSEFORMAT;
                cout<<"\n---------------------------------------------------------------\n";
                plan.calculate(); // BMI is displayed

                cout<< ITALIC <<"\n\nDisplaying Workout Plans.....\n"<< CLOSEFORMAT;
                plan.workout();     // Workout plans are displayed


                cout<< ITALIC <<"\n\nDisplaying Diet Plans.....\n"<< CLOSEFORMAT;
                plan.nutrition();   // Diet plans are displayed

                plan.save();        // Data is stored in a file
            }
              break;
            case 2:
            {
                cout<<"\n--------------------------------------------";
                cout<< BOLD <<"\n\n\tCALCULATE YOUR BODY MASS INDEX\n" << CLOSEFORMAT;
                cout<<"\n--------------------------------------------\n";
                plan.calculate();   // BMI is displayed
            }
              break;
            case 3:
            {
                cout<<"\n--------------------------------------------";
                cout<< BOLD <<"\n\n\tWORKOUTS FOR YOUR BMI\n"<< CLOSEFORMAT;
                cout<<"\n--------------------------------------------\n";

                cout<<"\n\nEnter your BMI: " <<BOLD;
                while(!(cin >> plan.bmi)) // using while loop - to accept only int as input
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout  << ITALIC << "\n--- Please enter valid input! ---\n\n" << CLOSEFORMAT <<"Enter the BMI obtained: ";
                }
                cout<< CLOSEFORMAT;
                plan.workout();     // Workout plans are displayed
            }
              break;
            case 4:
            {
                cout<<"\n--------------------------------------------";
                cout<< BOLD <<"\n\n\tDIET PLANS FOR YOUR BMI\n"<< CLOSEFORMAT;
                cout<<"\n--------------------------------------------\n";

                cout<<"\n\nEnter your BMI: "<<BOLD;

                // using while loop - to accept only int as input
                while(!(cin >> plan.bmi))                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<< ITALIC << "\n--- Please enter valid input! ---\n\n" << CLOSEFORMAT << "Enter the BMI obtained: ";
                }
                cout<< CLOSEFORMAT;
                plan.nutrition();// Diet plans are displayed
            }
              break;
            case 5:
              plan.faqs();
              break;
            case 6:
              cout<< ITALIC <<"\n--- This application is exited successfully ---\n\n"<< CLOSEFORMAT <<endl;
              exit(0);
              break;
            default:
            cout<< ITALIC <<"\n--- Invalid choice! ---\n"<< CLOSEFORMAT;
        }
    }
}





// Calculate BMI
void Diet::calculate()
{
    // Calculating Height
    do // do while loop - to choose only the provided options
    {
        cout<<"\nChoose the unit for your height\n";
        cout<<"\n1. Centimeter\n\n2. Meter\n\n3. Inches\n\n4. Feet\n\n";
        cout<< ITALIC <<"Enter your choice: ";
        while(!(cin >> ch1)) // using while loop - to accept int as input
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ITALIC << "\n--- Invalid input! ---\n\n" << "Enter your choice: " << CLOSEFORMAT ;
            }
        cout<< CLOSEFORMAT;

        if(ch1==1)// For Centimeter
        {
            cout<<"\nEnter your height in centimeters: ";
            while(!(cin >> height)) // using while loop to - accept int as input
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ITALIC << "\n--- Invalid input! ---\n\n" << CLOSEFORMAT << "Enter your height in"<<BOLD<<" centimeters: "<<CLOSEFORMAT;
            }
            height_in_meters = height / 100; // Formula to convert centemeters to meters
            cout<<"\nYour height: "<< UNDERLINE << setprecision(4) << height <<"cm"<< CLOSEFORMAT;

            break;
        }

        else if(ch1==2)// For Meter
        {
            cout<<"\nEnter your height in meters: ";
            while(!(cin >> height)) // using while loop - to accept int as input
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ITALIC << "\n--- Invalid input! ---\n\n" << CLOSEFORMAT << "Enter your height in"<<BOLD<<" meters: "<<CLOSEFORMAT;
            }
            height_in_meters = height;
            cout<<"\nYour height: "<< UNDERLINE << setprecision(3) << height <<"m"<< CLOSEFORMAT;
            break;
        }

        else if(ch1==3)// For Inches
        {
            cout<<"\nEnter your height in inches: ";
            while(!(cin >> height)) // using while loop - to accept int as input
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ITALIC << "\n--- Invalid input! ---\n\n" << CLOSEFORMAT << "Enter your height in"<<BOLD<<" inches: "<<CLOSEFORMAT;
            }
            height_in_meters = height * 0.0254; // Formula to convert inches to meters
            cout<<"\nYour height: "<< UNDERLINE << setprecision(3) << height <<"in"<< CLOSEFORMAT;
            break;
        }

        else if(ch1==4)// For Feet
        {
            cout<<"\nEnter your height in feet: ";
            while(!(cin >> height)) // using while loop - to accept int as input
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ITALIC << "\n--- Invalid input! ---\n\n" << CLOSEFORMAT << "Enter your height in"<<BOLD<<" feet: "<<CLOSEFORMAT;
            }
            height_in_meters = height * 0.3048; // Formula to convert feet to meters
            cout<<"\nYour height: "<< UNDERLINE << setprecision(3) << height <<"ft"<< CLOSEFORMAT;
            break;
        }

        else
        {
            cout<< ITALIC <<"\n--- Please enter valid input! ---\n\n"<< CLOSEFORMAT;
        }

    }while (ch1>=1 || ch1<=4);

    // Calculating Weight
    do // do while loop - to choose only the provided options*/
    {
        cout<<"\n\n\nChoose the unit for your weight\n";
        cout<<"\n1. Kilograms\n\n2. Pounds\n\n";
        cout<< ITALIC <<"Enter your choice: ";
        while(!(cin >> ch2)) // using while loop - to accept int as input
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ITALIC << "\n--- Invalid input! ---\n\n" << "Enter your choice: " << CLOSEFORMAT ;
            }
        cout<< CLOSEFORMAT;

        if(ch2==1)// For Kilograms
        {
            cout<<"\nEnter your weight in kilograms: ";
            while(!(cin >> weight)) // using while - loop to accept int as input
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ITALIC << "\n--- Invalid input! ---\n\n" << CLOSEFORMAT << "Enter your weight in"<<BOLD<<" kilograms: "<<CLOSEFORMAT;
            }
            weight_in_kg = weight;
            cout<<"\nYour weight: "<< UNDERLINE << setprecision(3) << weight <<"kg"<< CLOSEFORMAT;
            break;
        }

        else if(ch2==2)// For Pounds
        {
            cout<<"\nEnter your weight in pounds: ";
            while(!(cin >> weight)) // using while loop - to accept int as input
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ITALIC << "\n--- Invalid input! ---\n\n" << CLOSEFORMAT << "Enter your weight in"<<BOLD<<" pounds: "<<CLOSEFORMAT;
            }
            weight_in_kg = weight * 0.454; // Formula to convert pounds to kilograms
            cout<<"\nYour weight: "<< UNDERLINE << setprecision(3) << weight <<"lbs"<< CLOSEFORMAT;
            break;
        }

        else
        {
            cout<< ITALIC <<"\n--- Please enter valid input! ---\n"<< CLOSEFORMAT;
        }

    }while (ch2>=1 || ch2<=2);

    cout<< ITALIC <<"\n\n\nCalculating BMI.....\n"<< CLOSEFORMAT;

    // Formula to calculate BMI
    bmi = weight_in_kg/(height_in_meters * height_in_meters);

    // BMI is displayed
    cout<<"\n\nYour Body Mass Index (BMI) is: "<< BOLD << setprecision(3) << bmi << CLOSEFORMAT;

    if(bmi<15)
    {
        cout<<"\n\nYou are under the BMI category --> Starvation\n";
        cout<<"\n--- You seriously have to consult a doctor ---\n";

    }

    else if(bmi >= 15.1 && bmi <= 17.5)
    {
        cout<<"\n\nYou are under the BMI category --> Anorexic\n";
        cout<<"\n--- You have to consult a doctor and take medicines ---\n";
    }

    else if(bmi >= 17.6 && bmi <= 18.5)
    {
        cout<<"\n\nYou are under the BMI category --> Underweight\n";
        cout<<"\n--- You have to consult a doctor and join a gym ---\n";
    }

    else if(bmi >= 18.6 && bmi <= 24.9)
    {
        cout<<"\n\nYou are under the BMI category --> Ideal\n";
        cout<<"\n--- You are in optimal shape!! Good work! Just eat in limit and you won't get any health issues ---\n";
    }

    else if(bmi >= 25 && bmi <= 29.9)
    {
        cout<<"\n\nYou are under the BMI category --> Overweight\n";
        cout<<"\n--- You have to consult a doctor and join a gym and you should be in calorie deficit ---\n";
    }

    else if(bmi >= 30 && bmi <= 39.9)
    {
        cout<<"\n\nYou are under the BMI category --> Obese\n";
        cout<<"\n--- You have to consult a doctor and join a gym and you should be in calorie deficit ---\n";
    }

    else if(bmi >= 40)
    {
        cout<<"\n\nYou are under the BMI category --> Morbidly Obese\n";
        cout<<"\n--- You seriously have to consult a doctor and join a gym and you should be in calorie deficit ---\n";
    }
}

// Workout Plans
void Diet::workout()
{
    if(bmi<15)
    {
        cout<<"\n\nWorkouts you need to perform 3-4 times a week\n";
        cout << BOLD <<"\nWorkout\t\t   Counts" << CLOSEFORMAT;
        cout<<"\n-----------------------------------";
        cout<<"\nPUSHUPS     -> 3 sets of 15 reps \nPULLUPS     -> 2 sets of 10-15 reps\nSquats      -> 3 sets of 10-20 reps\nLatpulldown -> 3 sets of 10-20 reps\nDeadlift    -> 3 sets of 10-12 reps\n";

    }

    else if(bmi >= 15.1 && bmi <= 17.5)
    {
        cout<<"\n\nWorkouts you need to perform 3-5 times a week\n";
        cout << BOLD <<"\nWorkout\t\t   Counts" << CLOSEFORMAT;
        cout<<"\n-----------------------------------";
        cout<<"\nPUSHUPS     -> 3 sets of 15 reps \nPULLUPS     -> 2 sets of 10-15 reps\nSquats      -> 3 sets of 10-20 reps\nBench-press -> 3 sets of 10-15 reps\nCable chest -> 3 sets of 10-12 reps\n";
    }

    else if(bmi >= 17.6 && bmi <= 18.5)
    {
        cout<<"\n\nWorkouts you need to perform 3-5 times a week\n";
        cout << BOLD <<"\nWorkout\t\t   Counts" << CLOSEFORMAT;
        cout<<"\n-----------------------------------";
        cout<<"\nPUSHUPS     -> 3 sets of 15 reps \nPULLUPS     -> 2 sets of 10-15 reps\nSquats      -> 3 sets of 10-20 reps\nLatpulldown -> 3 sets of 10-20 reps\nDeadlift    -> 3 sets of 10-12 reps\n";
    }

    else if(bmi >= 18.6 && bmi <= 24.9)
    {
        cout<<"\n\nWorkouts you need to perform 3-6 times a week\n";
        cout << BOLD <<"\nWorkout\t\t   Counts" << CLOSEFORMAT;
        cout<<"\n-----------------------------------";
        cout<<"\nPUSHUPS     -> 3 sets of 15 reps \nPULLUPS     -> 2 sets of 10-15 reps\nSquats      -> 3 sets of 10-20 reps\nLatpulldown -> 3 sets of 10-20 reps\nDeadlift    -> 3 sets of 10-12 reps\n";
    }

    else if(bmi >= 25 && bmi <= 29.9)
    {
        cout<<"\n\nWorkouts you need to perform the entire week and sunday is restday\n";
        cout << BOLD <<"\n Day\t\t   Workouts" << CLOSEFORMAT ;
        cout<<"\n---------------------------------------";
        cout<<"\nMONDAY     -> Chest, Triceps and abs \nTUESDAY    -> Lat and biceps\nWEDNESDAY  -> Legs, shoulder and abs\nTHURSDAY   -> Chest and Triceps\nFRIDAY     -> Lat, biceps and abs\nSATURDAY   -> Legs and shoulder\nSUNDAY     -> "<<ITALIC<<"no workout\n"<<CLOSEFORMAT;
    }

    else if(bmi >= 30 && bmi <= 39.9)
    {
        cout<<"\n\nWorkouts you need to perform the entire week and have a personal trainer to guide you\n";
        cout << BOLD <<"\n Day\t\t   Workouts" << CLOSEFORMAT ;
        cout<<"\n---------------------------------------";
        cout<<"\nMONDAY     -> Chest, Triceps and abs \nTUESDAY    -> Lat and biceps\nWEDNESDAY  -> Legs, shoulder and abs\nTHURSDAY   -> Chest and Triceps\nFRIDAY     -> Lat, biceps and abs\nSATURDAY   -> Legs and shoulder\nSUNDAY     -> "<<ITALIC<<"no workout\n"<<CLOSEFORMAT;
    }

    else if(bmi >= 40)
    {
        cout<<"\n\nWorkouts you need to perform the entire week and have a personal trainer to guide you\n";
        cout << BOLD <<"\n Day\t\t   Workouts" << CLOSEFORMAT ;
        cout<<"\n---------------------------------------";
        cout<<"\nMONDAY     -> Chest, Triceps and abs \nTUESDAY    -> Lat and biceps\nWEDNESDAY  -> Legs, shoulder and abs\nTHURSDAY   -> Chest and Triceps\nFRIDAY     -> Lat, biceps and abs\nSATURDAY   -> Legs and shoulder\nSUNDAY     -> "<<ITALIC<<"no workout\n"<<CLOSEFORMAT;
    }
}

// Diet Plans
void Diet::nutrition()
{
    if(bmi<15)
    {
        cout<<"\n\nTotal Calories (kcals/Day) 2000-2200\n";
        cout << BOLD <<"\n\tTime\t\t\t\t\t\t\tMeal" << CLOSEFORMAT;
        cout<<"\n-----------------------------------------------------------------------------------------------------------------------------";
        cout<<"\nBreakfast (08:00 - 08:30AM)  -> 2 egg brown bread sandwich + green chutney + 1 cup milk + 3 cashews + 4 almonds + 2 walnuts \nMid-Meal  (11:00 - 11:30AM)  -> 1 cup banana shake\nLunch 	  (02:00 - 02:30PM)  -> 1 cup arhar dal + 1 cup potato curry + 3 chapatti + 1/2 cup rice + 1/2 cup low fat curd + salad\nEvening   (04:00 - 04:30PM)  -> 1 cup strawberry smoothie + 1 cup vegetable poha\nDinner 	  (08:00 - 08:30PM)  -> 1.5 cup chicken curry + 3 chapatti + salad\n";
    }

    else if(bmi >= 15.1 && bmi <= 17.5)
    {
        cout<<"\n\nTotal Calories (kcals/Day) 1800-2000\n";
        cout<< BOLD<<"\n\tTime\t\t\t\t\t\t\tMeal" << CLOSEFORMAT;
        cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
        cout<<"\nBreakfast (08:00 - 08:30AM)  -> 3 onion stuffed parantha + 1 cup curd + 4 almonds + 2 walnuts \nMid-Meal  (11:00 - 11:30AM)  -> 1 cup mango shake\nLunch 	  (02:00 - 02:30PM)  -> 1 cup moong dal/ chicken curry + 1 cup potato and caulifllower vegetable + 3 chapatti + 1/2 cup rice + salad\nEvening   (04:00 - 04:30PM)  -> 1 cup pomegranate juice + 2 butter toasted bread\nDinner 	  (08:00 - 08:30PM)  -> 1 cup beans potato vegetable + 3 chapatti\n";
    }

    else if(bmi >= 17.6 && bmi <= 18.5)
    {
        cout<<"\n\nTotal Calories (kcals/Day) 1600-1800\n";
        cout<< BOLD<<"\n\tTime\t\t\t\t\t\t\tMeal"<< CLOSEFORMAT;
        cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
        cout<<"\nBreakfast (08:00 - 08:30AM)  -> 3 paneer stuffed besan cheela + green chutney + 3 cashews + 4 almonds + 2 walnuts \nMid-Meal  (11:00 - 11:30AM)  -> 1 apple smoothie with maple syrup\nLunch 	  (02:00 - 02:30PM)  -> 1 cup masoor dal + 1 cup calocasia + 3 chapatti + 1 cup low curd + salad\nEvening   (04:00 - 04:30PM)  -> 1 cup tomato soup with bread crumbs\nDinner 	  (08:00 - 08:30PM)  -> 1 cup carrot peas vegetable +3 chapatti + salad\n";
    }

    else if(bmi >= 18.6 && bmi <= 24.9)
    {
        cout<<"\n\nTotal Calories (kcals/Day) 1450-1600\n";
        cout<< BOLD<<"\n\tTime\t\t\t\t\t\tMeal"<< CLOSEFORMAT;
        cout<<"\n--------------------------------------------------------------------------------------------------------------------";
        cout<<"\nBreakfast (08:00 - 08:30AM)  -> 1.5 cup vegetable bread upma + 1 cup milk + 3 cashews + 4 almonds + 2 walnuts \nMid-Meal  (11:00 - 11:30AM)  -> 1 cup ripe banana with 2 tsp ghee\nLunch 	  (02:00 - 02:30PM)  -> 1 cup rajma curry + 1 cup spinach potato + 1/2 cup rice + salad\nEvening   (04:00 - 04:30PM)  -> 1 cup vegetable juice \nDinner 	  (08:00 - 08:30PM)  -> 1.5 cup parwal vegetable + 3 chapatti\n";
    }

    else if(bmi >= 25 && bmi <= 29.9)
    {
        cout<<"\n\nTotal Calories (kcals/Day) 1250-1350\n";
        cout<< BOLD<<"\n\tTime\t\t\t\t\t\tMeal"<< CLOSEFORMAT;
        cout<<"\n-----------------------------------------------------------------------------------------------------";
        cout<<"\nBreakfast (08:00 - 08:30AM)  -> 1 orange juice + 3 cashews + 2 walnuts + 4 almonds \nMid-Meal  (11:00 - 11:30AM)  -> 1 cup sweet potato chaat\nLunch 	  (02:00 - 02:30PM)  -> 1 cup white chana/ fish curry + 3 chapatti + 1/2 cup rice + salad\nEvening   (04:00 - 04:30PM)  -> banana\nDinner 	  (08:00 - 08:30PM)  -> 3 chapatti + salad\n";
    }

    else if(bmi >= 30 && bmi <= 39.9)
    {
        cout<<"\n\nTotal Calories (kcals/Day) 900-1100\n";
        cout<< BOLD<<"\n\tTime\t\t\t\tMeal"<< CLOSEFORMAT;
        cout<<"\n--------------------------------------------------------------------------";
        cout<<"\nBreakfast (08:00 - 08:30AM)  -> 2 cup vegetable poha \nMid-Meal  (11:00 - 11:30AM)  -> "<<ITALIC<<"not needed"<<CLOSEFORMAT<<"\nLunch 	  (02:00 - 02:30PM)  -> 1 cup chana dal + 1/2 cup rice + salad\nEvening   (04:00 - 04:30PM)  -> green chutney\nDinner 	  (08:00 - 08:30PM)  -> 3 chapatti\n";
    }

    else if(bmi >= 40)
    {
        cout<<"\n\nTotal Calories (kcals/Day) 400-800\n";
        cout<< BOLD<<"\n\tTime\t\t\t\tMeal"<< CLOSEFORMAT;
        cout<<"\n-------------------------------------------------------";
        cout<<"\nBreakfast (08:00 - 08:30AM)  -> 3 vegetable suji cheela \nMid-Meal  (11:00 - 11:30AM)  -> "<<ITALIC<<"not needed"<<CLOSEFORMAT<<"\nLunch 	  (02:00 - 02:30PM)  -> 1 cup mix dal + 3 chapatti\nEvening   (04:00 - 04:30PM)  -> "<<ITALIC<<"not needed"<<CLOSEFORMAT<<"\nDinner 	  (08:00 - 08:30PM)  -> 3 chaptti\n";
    }
}

// Frequently Asked Questions
void Diet::faqs()
{
    cout<<"\n--------------------------------------------";
    cout<< BOLD <<"\n\n\tFAQs ABOUT BMI & DIET PLANS\n" << CLOSEFORMAT;
    cout<<"\n--------------------------------------------\n";
    cout<<"\n1) What is BMI?";
    cout<<"\n\n   BMI is an acronym for Body Mass Index, and it is an indicator of the amount of fat which is stored in the human body.";
    cout<<"\n\n2) How do diets work?";
    cout<<"\n\n   All diets work by restricting calories.";
    cout<<"\n\n3) Which fats should you cut back on to lose weight?";
    cout<<"\n\n   Saturated fats. Less than 10% of your calories should come from saturated fats.";
    cout<<"\n\n4) If you eat too much lunch, should you skip dinner? Yes or no?";
    cout<<"\n\n   No. Don't skip meals if you're trying to lose weight.";
    cout<<"\n\n5) To lose weight, you should plan every meal. True or false?";
    cout<<"\n\n   True. Spontaneity is great for some activities, but eating isn't one of them.";
    cout<<"\n\n6) Only working out can reduce my weight? ";
    cout<<"\n\n   Not at all! Diet plays an important role in your fat/weight loss journey. In a nutshell, 20% working out + 80% diet = FAT LOSS.";
}

// To save user data
void Diet::save()
{
    cout<< BOLD <<"\n\n\tDo you want to save your data? (y/n)\n"<< CLOSEFORMAT;
    cout<< ITALIC <<"\nEnter your choice: ";
    cin>>ch3;
    cout<<CLOSEFORMAT<<"\n";
    if(ch3 =='y' || ch3=='Y')
    {
        ofstream Report;
        cout << "Enter your name: ";
        cin >> your_name;
        Report.open(string(your_name+"'s BMI Report.txt").c_str());
        if (!Report)
        {
		    cout<< ITALIC << "\n--- File not created! ---"<< CLOSEFORMAT;
	    }
        else
        {
		    Report << "• Your Height: " << height;
            Report << "\n\n• Your Weight: " << weight;
            Report << "\n\n• Your Body Mass Index (BMI) is: "<< setprecision(3) << bmi;
            if(bmi<15)
            {
                Report << "\n\n• You are under the BMI category --> Starvation\n\n--- You seriously have to consult a doctor ---\n";
                Report << "\n\nWorkouts you need to perform 3-5 times a week\n \nWorkout\t\t   Counts \n-----------------------------------\nPUSHUPS     -> 3 sets of 15 reps \nPULLUPS     -> 2 sets of 10-15 reps\nSquats      -> 3 sets of 10-20 reps\nLatpulldown -> 3 sets of 10-20 reps\nDeadlift    -> 3 sets of 10-12 reps\n";
                Report << "\n\nTotal Calories (kcals/Day) 2000-2200\n\n\tTime\t\t\t\t\t\t\tMeal\n-----------------------------------------------------------------------------------------------------------------------------\nBreakfast (08:00 - 08:30AM)  -> 2 egg brown bread sandwich + green chutney + 1 cup milk + 3 cashews + 4 almonds + 2 walnuts \nMid-Meal  (11:00 - 11:30AM)  -> 1 cup banana shake\nLunch 	  (02:00 - 02:30PM)  -> 1 cup arhar dal + 1 cup potato curry + 3 chapatti + 1/2 cup rice + 1/2 cup low fat curd + salad\nEvening   (04:00 - 04:30PM)  -> 1 cup strawberry smoothie + 1 cup vegetable poha\nDinner 	  (08:00 - 08:30PM)  -> 1.5 cup chicken curry + 3 chapatti + salad\n";
            }
            else if(bmi >= 15.1 && bmi <= 17.5)
            {
                Report << "\n\nYou are under the BMI category --> Anorexic\n\n--- You have to consult a doctor and take medicines ---\n";
                Report << "\n\nWorkouts you need to perform 3-5 times a week\n\nWorkout\t\t   Counts\n-----------------------------------\nPUSHUPS     -> 3 sets of 15 reps \nPULLUPS     -> 2 sets of 10-15 reps\nSquats      -> 3 sets of 10-20 reps\nBench-press -> 3 sets of 10-15 reps\nCable chest -> 3 sets of 10-12 reps\n";
                Report << "\n\nTotal Calories (kcals/Day) 2000-2200\n\n\tTime\t\t\t\t\t\t\tMeal\n-----------------------------------------------------------------------------------------------------------------------------\nBreakfast (08:00 - 08:30AM)  -> 2 egg brown bread sandwich + green chutney + 1 cup milk + 3 cashews + 4 almonds + 2 walnuts \nMid-Meal  (11:00 - 11:30AM)  -> 1 cup banana shake\nLunch 	  (02:00 - 02:30PM)  -> 1 cup arhar dal + 1 cup potato curry + 3 chapatti + 1/2 cup rice + 1/2 cup low fat curd + salad\nEvening   (04:00 - 04:30PM)  -> 1 cup strawberry smoothie + 1 cup vegetable poha\nDinner 	  (08:00 - 08:30PM)  -> 1.5 cup chicken curry + 3 chapatti + salad\n";
            }
            else if(bmi >= 17.6 && bmi <= 18.5)
            {
                Report << "\n\nYou are under the BMI category --> Underweight\n\n--- You have to consult a doctor and join a gym ---\n";
                Report << "\n\nWorkouts you need to perform 3-5 times a week\n\nWorkout\t\t   Counts\n-----------------------------------\nPUSHUPS     -> 3 sets of 15 reps \nPULLUPS     -> 2 sets of 10-15 reps\nSquats      -> 3 sets of 10-20 reps\nLatpulldown -> 3 sets of 10-20 reps\nDeadlift    -> 3 sets of 10-12 reps\n";
                Report << "\n\nTotal Calories (kcals/Day) 2000-2200\n\n\tTime\t\t\t\t\t\t\tMeal\n-----------------------------------------------------------------------------------------------------------------------------\nBreakfast (08:00 - 08:30AM)  -> 2 egg brown bread sandwich + green chutney + 1 cup milk + 3 cashews + 4 almonds + 2 walnuts \nMid-Meal  (11:00 - 11:30AM)  -> 1 cup banana shake\nLunch 	  (02:00 - 02:30PM)  -> 1 cup arhar dal + 1 cup potato curry + 3 chapatti + 1/2 cup rice + 1/2 cup low fat curd + salad\nEvening   (04:00 - 04:30PM)  -> 1 cup strawberry smoothie + 1 cup vegetable poha\nDinner 	  (08:00 - 08:30PM)  -> 1.5 cup chicken curry + 3 chapatti + salad\n";
            }
            else if(bmi >= 18.6 && bmi <= 24.9)
            {
                Report << "\n\nYou are under the BMI category --> Ideal\n\n--- You are in optimal shape!! Good work! Just eat in limit and you won't get any health issues ---\n";
                Report << "\n\nWorkouts you need to perform 3-6 times a week\n\nWorkout\t\t   Counts\n-----------------------------------\nPUSHUPS     -> 3 sets of 15 reps \nPULLUPS     -> 2 sets of 10-15 reps\nSquats      -> 3 sets of 10-20 reps\nLatpulldown -> 3 sets of 10-20 reps\nDeadlift    -> 3 sets of 10-12 reps\n";
                Report << "\n\nTotal Calories (kcals/Day) 1450-1600\n\n\tTime\t\t\t\t\t\tMeal\n--------------------------------------------------------------------------------------------------------------------\nBreakfast (08:00 - 08:30AM)  -> 1.5 cup vegetable bread upma + 1 cup milk + 3 cashews + 4 almonds + 2 walnuts \nMid-Meal  (11:00 - 11:30AM)  -> 1 cup ripe banana with 2 tsp ghee\nLunch 	  (02:00 - 02:30PM)  -> 1 cup rajma curry + 1 cup spinach potato + 1/2 cup rice + salad\nEvening   (04:00 - 04:30PM)  -> 1 cup vegetable juice \nDinner 	  (08:00 - 08:30PM)  -> 1.5 cup parwal vegetable + 3 chapatti\n";
            }
            else if(bmi >= 25 && bmi <= 29.9)
            {
                Report << "\n\nYou are under the BMI category --> Overweight\n\n--- You have to consult a doctor and join a gym and you should be in calorie deficit ---\n";
                Report << "\n\nWorkouts you need to perform the entire week and sunday is restday\n\n Day\t\t   Workouts\n---------------------------------------\nMONDAY     -> Chest, Triceps and abs \nTUESDAY    -> Lat and biceps\nWEDNESDAY  -> Legs, shoulder and abs\nTHURSDAY   -> Chest and Triceps\nFRIDAY     -> Lat, biceps and abs\nSATURDAY   -> Legs and shoulder\nSUNDAY     -> no workout\n";
                Report << "\n\nTotal Calories (kcals/Day) 1250-1350\n\n\tTime\t\t\t\t\t\tMeal\n-----------------------------------------------------------------------------------------------------\nBreakfast (08:00 - 08:30AM)  -> 1 orange juice + 3 cashews + 2 walnuts + 4 almonds \nMid-Meal  (11:00 - 11:30AM)  -> 1 cup sweet potato chaat\nLunch 	  (02:00 - 02:30PM)  -> 1 cup white chana/ fish curry + 3 chapatti + 1/2 cup rice + salad\nEvening   (04:00 - 04:30PM)  -> banana\nDinner 	  (08:00 - 08:30PM)  -> 3 chapatti + salad\n";
            }
            else if(bmi >= 30 && bmi <= 39.9)
            {
                Report << "\n\nYou are under the BMI category --> Obese\n\n--- You have to consult a doctor and join a gym and you should be in calorie deficit ---\n";
                Report << "\n\nWorkouts you need to perform the entire week and have a personal trainer to guide you\n\n Day\t\t   Workouts\n---------------------------------------\nMONDAY     -> Chest, Triceps and abs \nTUESDAY    -> Lat and biceps\nWEDNESDAY  -> Legs, shoulder and abs\nTHURSDAY   -> Chest and Triceps\nFRIDAY     -> Lat, biceps and abs\nSATURDAY   -> Legs and shoulder\nSUNDAY     -> ";
                Report << "\n\nTotal Calories (kcals/Day) 900-1100\n\n\tTime\t\t\t\tMeal\n--------------------------------------------------------------------------\nBreakfast (08:00 - 08:30AM)  -> 2 cup vegetable poha \nMid-Meal  (11:00 - 11:30AM)  -> not needed\nLunch 	  (02:00 - 02:30PM)  -> 1 cup chana dal + 1/2 cup rice + salad\nEvening   (04:00 - 04:30PM)  -> green chutney\nDinner 	  (08:00 - 08:30PM)  -> 3 chapatti\n";
            }
            else if(bmi >= 40)
            {
                Report << "\n\nYou are under the BMI category --> Morbidly Obese\n\n--- You seriously have to consult a doctor and join a gym and you should be in calorie deficit ---\n";
                Report << "\n\nWorkouts you need to perform the entire week and have a personal trainer to guide you\n\n Day\t\t   Workouts\n---------------------------------------\nMONDAY     -> Chest, Triceps and abs \nTUESDAY    -> Lat and biceps\nWEDNESDAY  -> Legs, shoulder and abs\nTHURSDAY   -> Chest and Triceps\nFRIDAY     -> Lat, biceps and abs\nSATURDAY   -> Legs and shoulder\nSUNDAY     -> no workout\n";
                Report << "\n\nTotal Calories (kcals/Day) 400-800\n\n\tTime\t\t\t\tMeal\n-------------------------------------------------------\nBreakfast (08:00 - 08:30AM)  -> 3 vegetable suji cheela \nMid-Meal  (11:00 - 11:30AM)  -> not needed\nLunch 	  (02:00 - 02:30PM)  -> 1 cup mix dal + 3 chapatti\nEvening   (04:00 - 04:30PM)  -> not needed\nDinner 	  (08:00 - 08:30PM)  -> 3 chaptti\n";
            }
            Report << "\n\n\n\t\t\t\t--- Thank you visit again ---";
            cout << ITALIC << "\n--- Your file has been saved successfully ---"<< CLOSEFORMAT;
		    Report.close();
        }
    }
    else
    {

        cout<< ITALIC << "--- File not created! ---"<< CLOSEFORMAT;
    }
}
