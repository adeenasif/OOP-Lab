#include<iostream>
using namespace std;


class Flight {
	string flightNum, departure, arrival;
	const int capacity;
	int num;
	int *bookedIDs;
	
	public:
		Flight (string Fnum, string dept, string arr, int cap) : capacity(cap) {
			flightNum = Fnum;
			departure = dept;
			arrival = arr;
			num = 0; 
			bookedIDs = new int[cap];
		}
		~Flight() {
	        delete[] bookedIDs;
	    }

		bool isBooked(int passengerID) {
	        for (int i = 0; i < num; i++) {
	            if (bookedIDs[i] == passengerID) return true;
	        }
	        return false;
    	}
    
		void bookSeat(int passengerID) {
			if (!isBooked(passengerID) && num < capacity) {
				bookedIDs[num++] = passengerID;
        		cout << "Passenger " << passengerID << " booked successfully on flight " << flightNum << endl;
    		} else {
				cout << "Booking Failed!! Max Capacity reached of flight " << flightNum << endl;
			}
		}
		
		void cancelSeat(int passengerID) {
	        for (int i = 0; i < num; ++i) {
	            if (bookedIDs[i] == passengerID) {
	                for (int j = i; j < num - 1; j++) {
	                    bookedIDs[j] = bookedIDs[j + 1];
	                }
	                num--;
	                cout << "Passenger " << passengerID << " cancelled booking on flight " << flightNum << endl;
	                return;
	            }
	        }
	        cout << "Passenger " << passengerID << " was not found on flight " << flightNum << endl;
	    }
			
		void upgradeSeat(int passengerID) {
	        if (isBooked(passengerID)) {
	            cout << "Passenger " << passengerID << " upgraded seat on flight " << flightNum << endl;
	        } else {
	            cout << "Upgrade failed: Passenger " << passengerID << " is not booked." << endl;
	        }
	    }
	    
	    void flightInfo() {
        	cout << "Flight " << flightNum << endl;
			cout << "Departure From: " << departure << " To: " << arrival << endl;
        	cout << "Seats booked: " << num << "/" << capacity << endl;
    	}
};

class Passenger {
	int id;
	string name;
	
	public:
		Passenger(int ID, string n) {
			id = ID;
			name = n;
		}
		void requestBooking(Flight& f) {
			f.bookSeat(id);
		}
		void requestCancel(Flight& f) {
	        f.cancelSeat(id);
	    }
	
	    void requestUpgrade(Flight& f) {
	        f.upgradeSeat(id);
	    }
};

int main() {
    Flight f1("PK101", "Lahore", "Dubai", 2);
    Flight f2("PK202", "Karachi", "Istanbul", 1);

    Passenger p1(1, "Ali");
    Passenger p2(2, "Zara");
    Passenger p3(3, "Sara");
	
	cout << " ---- BOOKING DETAILS ---- " << endl;
    p1.requestBooking(f1); // success
    p2.requestBooking(f1); // success
    p3.requestBooking(f1); // should fail (full)
	
	cout << "\n ---- FLIGHT UPGRADATION ---- " << endl;
    p2.requestUpgrade(f1); // success
    p3.requestUpgrade(f1); // fail

	cout << "\n ---- FLIGHT CANCELLATION ---- " << endl;
    p2.requestCancel(f1); // cancel Zara
    
	cout << endl;
    p3.requestBooking(f1); // now Sara can book

    cout << "\n ---- FLIGHT INFO ---- " << endl;
    f1.flightInfo();
    cout << endl;
    f2.flightInfo();

    // Prevent direct access
    // f1.capacity--; // ERROR: capacity is const
    // cout << f1.flightNum; // ERROE: private member cannot be accessed directly

    return 0;
}
