#include<iostream>
using namespace std;

class Student {
	public:
	    virtual double getTuition(string status, int creditHrs) = 0;
	    virtual ~Student() {} 
};

class GraduateStudent : public Student {
	private:
	    string researchTopic;
	
	public:
	    void setTopic(string topic) {
	        researchTopic = topic;
	    }
	    string getTopic() {
	        return researchTopic;
	    }
	
	    double getTuition(string status, int creditHrs) override {
	        if (status == "undergraduate") {
	            return 200 * creditHrs;
	        } else if (status == "graduate") {
	            return 300 * creditHrs;
	        } else if (status == "doctoral") {
	            return 400 * creditHrs;
	        } else {
	            cout << "INVALID STATUS: Enter one of these: undergraduate / graduate / doctoral!";
	            return 0.0;
	        }
	    }
};

int main() {
    GraduateStudent gs;

    gs.setTopic("Artificial Intelligence");
    cout << "Research Topic: " << gs.getTopic() << endl;

    cout << "\nTuition fee of graduate student: $" << gs.getTuition("graduate", 3) << endl;
    cout << "Tuition fee of undergraduate student: $" << gs.getTuition("undergraduate", 2) << endl;
    cout << "Tuition fee of doctoral student: $" << gs.getTuition("doctoral", 4) << endl;
    cout << " Fees: $" << gs.getTuition("masters", 3) << endl;

    return 0;
}

