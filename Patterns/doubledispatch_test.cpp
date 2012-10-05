
#include "lldoubledispatch.h"
#include "common.h"



class GameObject : public Verbose
{
public:
    GameObject(const string& name): Verbose(name) {}
    virtual ~GameObject() {}
    virtual string stringize() { return string(typeid(*this).name()) + " " + mName; }

protected:
    string mName;
};

// SpaceStation, Asteroid and SpaceShip are peer GameObjects.
struct SpaceStation: public GameObject
{
    SpaceStation(const string& name): GameObject(name) {}
    // Only a dummy SpaceStation is constructed without a name
    SpaceStation(): GameObject("SpaceStation dummy") {}
};

struct Asteroid: public GameObject
{
    Asteroid(const string& name): GameObject(name) {}
    Asteroid(): GameObject("Asteroid dummy") {}
};

struct SpaceShip: public GameObject
{
    SpaceShip(const string& name): GameObject(name) {}
    SpaceShip(): GameObject("SpaceShip dummy") {}
};

// SpaceShip is specialized further into CommercialShip and MilitaryShip.
struct CommercialShip: public SpaceShip
{
    CommercialShip(const string& name): SpaceShip(name) {}
    CommercialShip(): SpaceShip("CommercialShip dummy") {}
};

struct MilitaryShip: public SpaceShip
{
    MilitaryShip(const string& name): SpaceShip(name) {}
    MilitaryShip(): SpaceShip("MilitaryShip dummy") {}
};

/*-------------------------- Collision functions ---------------------------*/
// This mechanism permits us to overcome a limitation of Meyers' approach:  we
// can declare the parameter types exactly as we want, rather than having to
// make them all GameObject& parameters.
string shipAsteroid(SpaceShip& ship, Asteroid& rock)
{
  cout << rock << " has pulverized " << ship << endl;
    return "shipAsteroid";
}

string militaryShipAsteroid(MilitaryShip& ship, Asteroid& rock)
{
  cout << rock << " has severely damaged " << ship << endl;
    return "militaryShipAsteroid";
}

string shipStation(SpaceShip& ship, SpaceStation& dock)
{
  cout << ship << " has docked at " << dock << endl;
    return "shipStation";
}

string asteroidStation(Asteroid& rock, SpaceStation& dock)
{
  cout << rock << " has damaged " << dock << endl;
    return "asteroidStation";
}

void test_double_dispatcher()
{
    {
        cout << "---- test_double_dispatcher test 1 ---- " << endl;

        // Instantiate and populate the DoubleDispatch object.
        typedef LLDoubleDispatch<string, GameObject> DD;
        DD dispatcher;

        // Instantiate a few GameObjects.  Make sure we refer to them
        // polymorphically, and don't let them leak.
        auto_ptr<GameObject> home(new SpaceStation("Terra Station"));
        auto_ptr<GameObject> obstacle(new Asteroid("Ganymede"));
        auto_ptr<GameObject> tug(new CommercialShip("Pilotfish"));
        auto_ptr<GameObject> patrol(new MilitaryShip("Enterprise"));


        // Describe param types using explicit DD::Type objects
        // (order-sensitive add() variant)
        dispatcher.add(DD::Type<SpaceShip>(), DD::Type<Asteroid>(), shipAsteroid, true);
        dispatcher.add(DD::Type<SpaceShip>(), DD::Type<SpaceStation>(), shipStation, true);
        dispatcher.add(DD::Type<Asteroid>(), DD::Type<SpaceStation>(), asteroidStation, true);

        // Try colliding them.
        dispatcher(*home, *tug);        // reverse params, SpaceShip subclass
        dispatcher(*patrol, *home);     // forward params, SpaceShip subclass
        dispatcher(*obstacle, *home);   // forward params
        dispatcher(*home, *obstacle);   // reverse params
        dispatcher(*tug, *obstacle);    // forward params, SpaceShip subclass
        dispatcher(*obstacle, *patrol); // reverse params, SpaceShip subclass
    }

    {
        cout << "---- test_double_dispatcher test 2 ---- " << endl;
        // Instantiate and populate the DoubleDispatch object.
        typedef LLDoubleDispatch<std::string, GameObject> DD;
        DD dispatcher;

        // Instantiate a few GameObjects.  Make sure we refer to them
        // polymorphically, and don't let them leak.
        auto_ptr<GameObject> home(new SpaceStation("Terra Station"));
        auto_ptr<GameObject> obstacle(new Asteroid("Ganymede"));
        auto_ptr<GameObject> tug(new CommercialShip("Pilotfish"));
        auto_ptr<GameObject> patrol(new MilitaryShip("Enterprise"));

        // prototype objects
        Asteroid dummyAsteroid;
        SpaceShip dummyShip;
        MilitaryShip dummyMilitary;
        CommercialShip dummyCommercial;
        SpaceStation dummyStation;

        dispatcher.add(dummyMilitary, dummyAsteroid, militaryShipAsteroid);
        dispatcher.add(dummyShip, dummyAsteroid, shipAsteroid);
        dispatcher.add(dummyShip, dummyStation, shipStation);
        dispatcher.add(dummyAsteroid, dummyStation, asteroidStation);

        dispatcher(*patrol, *obstacle);
        dispatcher(*tug, *obstacle);
        dispatcher(*obstacle, *patrol);
    }

    {
        cout << "---- test_double_dispatcher test 3 ---- " << endl;
        // Instantiate and populate the DoubleDispatch object.
        typedef LLDoubleDispatch<std::string, GameObject> DD;
        DD dispatcher;

        // Instantiate a few GameObjects.  Make sure we refer to them
        // polymorphically, and don't let them leak.
        auto_ptr<GameObject> home(new SpaceStation("Terra Station"));
        auto_ptr<GameObject> obstacle(new Asteroid("Ganymede"));
        auto_ptr<GameObject> tug(new CommercialShip("Pilotfish"));
        auto_ptr<GameObject> patrol(new MilitaryShip("Enterprise"));

        dispatcher.add<SpaceShip, Asteroid>(shipAsteroid);
        dispatcher.add<MilitaryShip, Asteroid>(militaryShipAsteroid);
        dispatcher.add<SpaceShip, SpaceStation>(shipStation);
        dispatcher.add<Asteroid, SpaceStation>(asteroidStation);

        dispatcher(*patrol, *obstacle);
        dispatcher(*tug, *obstacle);
    }
}
