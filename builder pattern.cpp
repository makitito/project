#include <iostream>
#include <string>

class Championsleague
{
    public:
        int cups;
};

class Domesticleague
{
    public:
        int titles;
};

class Manager
{
    public:
        std::string name;
};

class Rank
{
    public:
        Championsleague*   championsleagues;
        Domesticleague*  domesticleague;
        Manager* manager;
    
        void specifications()
        {
            std::cout << "manager:" << manager->name << std::endl;
            std::cout << "domesticleague titles:" << domesticleague->titles << std::endl;
            std::cout << "tire cups:" << championsleagues->cups << "'" << std::endl;
        }
};


class Builder
{
    public:
        virtual Championsleague* getChampionsleague() = 0;
        virtual Domesticleague* getDomesticleague() = 0;
        virtual Manager* getManager() = 0;
};


class Director
{
    Builder* builder;

    public:
        void setBuilder(Builder* newBuilder)
        {
            builder = newBuilder;
        }

        Rank* getRank()
        {
            Rank* rank = new Rank();

            rank->manager = builder->getManager();

            rank->domesticleague = builder->getDomesticleague();

            rank->championsleagues = builder->getChampionsleague();
            

            return rank;
        }
};


class RealmadridBuilder : public Builder
{
    public:
        Championsleague* getChampionsleague()
        {
            Championsleague* championsleague = new Championsleague();
            championsleague->cups = 11;
            return championsleague;
        }

        Domesticleague* getDomesticleague()
        {
            Domesticleague* domesticleague = new Domesticleague();
            domesticleague->titles = 32;
            return domesticleague;
        }

        Manager* getManager()
        {
            Manager* manager = new Manager();
            manager->name = "Zinedine Zidane";
        }
};


class AcmilanBuilder : public Builder
{
    public:
        Championsleague* getChampionsleague()
        {
            Championsleague* championsleague = new Championsleague();
            championsleague->cups = 7;
            return championsleague;
        }

        Domesticleague* getDomesticleague()
        {
            Domesticleague* domesticleague = new Domesticleague();
            domesticleague->titles = 18;
            return domesticleague;
        }

        Manager* getManager()
        {
            Manager* manager = new Manager();
            manager->name = "Vincenzo Montella";
        }
};


int main()
{
    Rank* rank; 

    
    Director director;

   
    RealmadridBuilder realmadridBuilder;
    AcmilanBuilder acmilanBuilder;

    
    std::cout << "Real Madrid" << std::endl;
    director.setBuilder(&realmadridBuilder); 
    rank = director.getRank();
    rank->specifications();

    std::cout << std::endl;

    
    std::cout << "AC Milan" << std::endl;
    director.setBuilder(&acmilanBuilder); 
    rank = director.getRank();
    rank->specifications();

    return 0;
}