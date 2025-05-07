/* MOCK QUESTIONS Q1: 
Sophie is developing a scientific simulation application that requires handling various physical entities. She wants to represent these entities using a class hierarchy. 
The entities can be of different types, such as particles, celestial bodies, and subatomic particles. To make the system efficient and flexible, 
Sophie decides to use templates to create a generic data structure for handling these entities. Additionally, she wants to implement polymorphism using abstract 
classes to allow for specialized behavior for each type of entity. Define an abstract base class called "Entity" with pure virtual functions getName() and 
getMass(). The getName() function should return a string representing the name of the entity, and the getMass() function should return a double representing the mass of the entity. 5 points 
Derive three classes from the "Entity" base class - "Particle," "CelestialBody," and "SubatomicParticle." Implement their respective versions of the pure virtual functions. 2 points 
Define a class called "Properties" that will contain additional properties specific to each type of entity. For example, a "Particle" might have charge and velocity properties, a "CelestialBody" 
might have information about its orbit and gravitational force, and a "SubatomicParticle" might have properties related to its quantum state. 3 points 
Derive the "Particle," "CelestialBody," and "SubatomicParticle" classes further to represent specific types of entities within each category. For instance, for "Particle," you can have classes 
like "Electron," "Proton," and "Neutron." Implement the necessary functions and member variables in these derived classes. 3 points 
Create a templated class called "EntityContainer" that can store and manage different types of entities. The class should have a container to store entity objects and member functions to add 
entities, display their names, calculate the total mass of all entities, and retrieve specific properties based on the entity's type. 6 points 
In the main function, demonstrate polymorphism by creating objects of each entity type (particles, celestial bodies, and subatomic particles) and storing them in the "EntityContainer" 
object. Use the member functions of the "EntityContainer" class to add entities, display their names, calculate the total mass, and retrieve specific properties based on the entity's type. 6 points
*/
#include<iostream>
#include<vector>
using namespace std;

class Entity {
	protected:
		string types;
	public:
		virtual string getName() = 0; // pure virtual function
		virtual double getMass() = 0; // pure virtual function
		virtual ~Entity() {}
};

class Particle : virtual public Entity {
	public:
		string getName() override {
			return "Particle";
		}
		double getMass() override {
			return 2.3;  //assuming mass
		}
};

class CelestialBody : virtual public Entity {
	public:
		string getName() override {
			return "Celestial Body";
		}
		double getMass() override {
			return 3.3;  //assuming mass
		}
};

class SubAtomicParticle : virtual public Entity {
	public:
		string getName() override {
			return "SubAtomic Particle";
		}
		double getMass() override {
			return 1.5;  //assuming mass
		}
};

class Properties {
	public :
		virtual void displayProperties () = 0;
		virtual ~Properties () {}
};

class ParticleProperties : public Properties {
	private:
		double charge; // + or -
		double velocity;
	public :
		ParticleProperties(double c, double v) : charge(c), velocity(v) {}
		
		void displayProperties () override {
			cout << "Charge : " << charge << endl;
			cout << "Velocity : " << velocity << endl;
		}
};

class CelestialProperties : public Properties {
	private:
		string orbitInfo; 
		string forceInfo;
	public :
		CelestialProperties(string Oinfo, string fInfo) : orbitInfo(Oinfo), forceInfo(fInfo) {	}
		
		void displayProperties () override {
			cout << "Orbit Info : " << orbitInfo << endl;
			cout << "Force Info : " << forceInfo << endl;
		}
};

class SubAtomicProperties : public Properties {
	private:
		string quantumState; 
	public :
		SubAtomicProperties(string state) : quantumState(state) {	}
		
		void displayProperties () override {
			cout << "Quantum State : " << quantumState << endl;
		}
};

class Electron : public Particle {
	public:
		string getName() override {
			return "ELECTRON";
		}
};

class Proton : public Particle {
	public:
		string getName() override {
			return "PROTON";
		}
};

class Neutron : public Particle {
	public:
		string getName() override {
			return "NEUTRON";
		}
};

class Quarks : public SubAtomicParticle {
	public:
		string getName() override {
			return "QUARK";
		}
};

class Moon : public CelestialBody {
	public:
		string getName() override {
			return "MOON";
		}
};

template <typename T>
class EntityContainer {
	private:
		vector<T>container;
	public:
		void addEntities(const T& entity){
			container.push_back(entity);
			cout << "Entity added!!! " << endl;
		}
		void display(const T& entity){
			cout << "Type : " << entity->getName() << endl;
			cout << "Mass : " << entity->getMass() << endl;
		}
		void calcMass(){
			double totalMass = 0.0;
			for (const auto& ent : container) {
				totalMass += ent->getMass();
			}
			cout << "\nTOTAL MASS = " << totalMass << endl;
		}
		void retrieve(const T& entity){
			if (entity->getName() == "Particle") {
				ParticleProperties pp(23.5, 45.4);
				pp.displayProperties();
			} else if (entity->getName() == "SubAtomic Particle") {
				SubAtomicProperties sp("idk");
				sp.displayProperties();
			} else if (entity->getName() == "Celestial Body") {
				CelestialProperties cp("Moon", "Black");
				cp.displayProperties();
			} 
		}
};

int main() {
	Particle p;
	CelestialBody c;
	SubAtomicParticle s;
	EntityContainer<Entity*> container;

	cout << " ---- PARITCLE POLYMORPHISM ---- " << endl;
	string pN = p.getName();
	cout << "Entity Type: " << pN << endl;
	double pM = p.getMass();
	cout << "Mass: " << pM << endl;
	
	cout << "\n ---- CELESTIAL BODY POLYMORPHISM ---- " << endl;
	string cN = c.getName();
	cout << "Entity Type: " << cN << endl;
	double cM = c.getMass();
	cout << "Mass: " << cM << endl;
	
	cout << "\n ---- SUB ATOMIC PARITCLE POLYMORPHISM ---- " << endl;
	string sN = s.getName();
	cout << "Entity Type: " << sN << endl;
	double sM = s.getMass();
	cout << "Mass: " << sM << endl;
	
	container.addEntities(&p);
	container.addEntities(&c);
	container.addEntities(&s);
	
	container.display(&p);
	container.display(&c);
	container.display(&s);
	
	container.calcMass();
	cout << "\n ---- RETRIEVEING SPECIFIC PROPERTIES OF PARTICLE ---- " << endl;
	container.retrieve(&p);
	
	cout << "\n ---- RETRIEVEING SPECIFIC PROPERTIES OF SUB ATOMIC PARTICLE ---- " << endl;
	container.retrieve(&s);
	
	cout << "\n ---- RETRIEVEING SPECIFIC PROPERTIES OF CELESTIAL BODY ---- " << endl;
	container.retrieve(&c);
	return 0;
}
