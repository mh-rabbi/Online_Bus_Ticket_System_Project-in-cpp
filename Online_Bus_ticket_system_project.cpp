#include <iostream>
#include <string>
using namespace std;

const int rows = 4;
const int cols = 4;

class Base
{
public:
    //Pure virtual Function Declaration
    virtual void cancelTicket() = 0;
};

class Bus
{
protected:
    string arrival, departure, from, Destination;
    bool seat[rows][cols];

public:
    //Constructor to initialize All the Bus Seat as Available
    Bus()
    {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                seat[i][j] = true;
    }
    //Setter And Getter Method to ensure proper Encapsulation

    void setArrival(string arrival)
    {
        this->arrival = arrival;
    }

    string getArrival()
    {
        return arrival;
    }

    void setDeparture(string departure)
    {
        this->departure = departure;
    }

    string getDeparture()
    {
        return departure;
    }

    void setBusfrom(string from)
    {
        this->from = from;
    }

    string getBusfrom()
    {
        return from;
    }

    void setDestination(string Destination)
    {
        this->Destination = Destination;
    }

    string getDestination()
    {
        return Destination;
    }
//Displaying Bus Details


    void displayBusdetails()
    {
        cout << "Bus Arrival Time     :"<< arrival << endl;
        cout << "Bus Departure Time   :"<< departure << endl;
        cout << "Bus is Leaving From  :"<< from << endl;
        cout << "Bus Destination      :"<< Destination << endl;
    }
};
//Use Of Inheritance
class PassengerSeat : private Bus, private Base
{
private:
    char rowSeat;
    int colSeat;
    string customerName;

public:
    //Explicit Constructor Call for PassengerSeat Class
    PassengerSeat() : Bus() {}
//Functionalities
    void displayAvailable_seats();
    void buyTicket();
    void cancelInfo();
    void cancelTicket() override;
    void bookingInfo();
};
void PassengerSeat::displayAvailable_seats()
{
    char rowLabel = 'A';
    cout << "Here Are The Available seats:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        cout << "For row-" << rowLabel << ": ";
        for (int j = 0; j < cols; ++j)
        {
            if (seat[i][j])
            {
                cout << rowLabel << j + 1 << " ";
            }
            else
            {
                //X is Used to indicate the Seat is Booked
                cout << "X ";
            }
        }
        //After End of Inner Loop [Column]
        //Incrementing Row Label Here RowLabel++ = A++ = B;
        ++rowLabel;
        cout << endl;

    }
    cout << endl;
}
//Taking Passenger Info and Which Seat He/She Wants to Book
void PassengerSeat::bookingInfo()
{
    cout << "Enter Name of the Customer: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "\nEnter from Which Row Label you want to book Seat [A, B, C, D]:";
    cin >> rowSeat;
    cout << "Enter From Which Column you want to book seat [1, 2, 3, 4]   :";
    cin >> colSeat;
}
void PassengerSeat::buyTicket()
{
    bookingInfo();
    int rowIndex = rowSeat - 'A';
    int colIndex = colSeat - 1;
    //Using While Loop To check whether the Array index is out of Bound

    while (rowIndex < 0 || rowIndex >= rows || colIndex < 0 || colIndex >= cols)
    {
        cout << "Invalid Seat Number" << endl;
        cout << "Please Enter Correct Information:" << endl;
        //Calling bookingInfo Function Again for taking Valid information
        bookingInfo();
        rowIndex = rowSeat - 'A';
        colIndex = colSeat - 1;
    }
    //Booking The Seat For the Customer
    if (seat[rowIndex][colIndex])
    {
        seat[rowIndex][colIndex] = false;
        cout << "Thank You Mr./Ms. " << customerName << " for your Purchase" << endl;
        cout << "Your Ticket has been booked Successfully" << endl;
    }
    else
    {
        cout << "This Seat is Already Booked" << endl;
    }
}
//Taking Info For Cancellation of Booked Seat
void PassengerSeat::cancelInfo()
{
    cout << "Enter Name of the Customer: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "\nEnter from Which Row Label you want to Cancel your Seat [A, B, C, D]: ";
    cin >> rowSeat;
    cout << "Enter From Which Column you want to Cancel your seat [1, 2, 3, 4]   : ";
    cin >> colSeat;
}
void PassengerSeat::cancelTicket()
{
    cancelInfo();
    int rowIndex = rowSeat - 'A';
    int colIndex = colSeat - 1;
    //Using While Loop To check whether the Array index is out of Bound
    while (rowIndex < 0 || rowIndex >= rows || colIndex < 0 || colIndex >= cols)
    {
        cout << "Invalid Seat Number" << endl;
        cout << "Please Enter Correct Information:" << endl;
        //Calling cancelInfo Function Again for taking Valid information
        cancelInfo();
        rowIndex = rowSeat - 'A';
        colIndex = colSeat - 1;
    }
//Canceling Booked Seat and Assigning the truth value to it
//If the Value of seat[rowIndex][colIndex] not True than Proceed to Cancel the Booking
//!if(condition) negates the value
//in case of boolean if the condition is true it makes false if the condition is false than it makes it true
//if(condition) here if the seat is not booked seat[rowIndex][colIndex]=true
//!if(condition) than it will be true and the if block will be executed
//otherwise else block will be executed
    if (!seat[rowIndex][colIndex])
    {
        seat[rowIndex][colIndex] = true;
        cout << "Your Booking has been canceled Successfully " << endl;
    }
    else
    {
        cout << "This Seat was not booked" << endl;
    }
}
//Option-Menu

void displayMenu()
{
    cout << "============================================================================================================================================================" << endl;
    cout << "\t\t\t\t\t\t\t\t\tWelcome to IUBAT Bus Service" << endl;
    cout << "============================================================================================================================================================" << endl;
    cout << "\t1. Display BUS Details" << endl;
    cout << "\t2. Buy a Bus Ticket" << endl;
    cout << "\t3. Cancel Ticket" << endl;
    cout << "\t4. Exit" << endl;
    cout << "\t   Please Enter Your Choice:\n\n ";
}

int main()
{
    const int busNo = 3;
    Bus bus[busNo];
    PassengerSeat passenger[busNo];
//Initializing Bus Details using Setter Method
    bus[0].setArrival("8:30 AM");
    bus[0].setDeparture("9:30 AM");
    bus[0].setBusfrom("Uttara");
    bus[0].setDestination("Mohakhali");

    bus[1].setArrival("9:30 AM");
    bus[1].setDeparture("10:30 AM");
    bus[1].setBusfrom("Uttara");
    bus[1].setDestination("Gazipur");

    bus[2].setArrival("10:30 AM");
    bus[2].setDeparture("11:30 AM");
    bus[2].setBusfrom("Uttara");
    bus[2].setDestination("Noakhali");

    int op;
    do
    {
        displayMenu();
        cin >> op;
        switch (op)
        {
        case 1:
            for (int i = 0; i < busNo; ++i)
            {
                cout << "\n===========================================================================================" << endl;
                cout<<"Bus No: "<<i+1<<endl;
                bus[i].displayBusdetails();
                cout << "\n===========================================================================================\n" << endl;
            }
            break;
        case 2:
        {
            // Buying a Ticket for Designated destination
            string destination;
            cout << "Enter your Destination: ";
            cin >> destination;
            bool found = false;
            for (int i = 0; i < busNo; ++i)
            {
                if (bus[i].getDestination() == destination)
                {
                    found = true;
                    cout << "Here are the Seats Available for this Bus" << endl;
                    passenger[i].displayAvailable_seats();
                    passenger[i].buyTicket();

                    break;
                }
            }

            if (!found)
            {
                cout << "Bus is not Available for " << destination << endl;
            }
            break;
        }
        case 3:
        {
            // Canceling a Ticket
            string dest;
            cout << "Enter the Bus destination for the ticket you want to cancel: ";
            cin >> dest;
            bool found = false;
            for (int i = 0; i < busNo; ++i)
            {
                if (bus[i].getDestination() == dest)
                {
                    found = true;
                    passenger[i].cancelTicket();
                    break;
                }
            }
            if (!found)
            {
                cout << "Please Enter the correct Information" << endl;
            }
            break;
        }
        case 4:
            exit(0);
        default:
            cout << "Invalid Input" << endl;
            cout << "Enter Correct Option: ";
            break;
        }
    }
    while (op != 4);

    return 0;
}
