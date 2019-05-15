#include <iostream>

using namespace std;

class Car
{
    private:
        unsigned int m_nSpeed;
        unsigned int m_nGear;
        string m_strType;
    public :
        Car(){
            m_nGear = 1;
            m_nSpeed = 1;
            m_strType = "K3";
        }
        void SetGear(unsigned int gear) { m_nGear = gear; }
        void SetSpeed(unsigned int speed) { m_nSpeed = speed; }
        void SetType(string type) { m_strType = type; }
        void speedUp() {m_nSpeed++;}
        void gearUp() {m_nSpeed++;}

        unsigned int getSpeed(){return m_nSpeed;}
        unsigned int getGear(){return m_nGear;}
        string getType(){return m_strType;}
};


int main()
{
    Car car1;
    cout << car1.getType() <<endl;


}