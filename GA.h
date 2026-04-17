#ifndef GA_HPP
#define GA_HPP

#include <iostream>
#include <vector>
#include <array>

struct BezierPoint {
        float x;
        float y;
    };

class GeneticAlgorithm
{
    private:
    //fitness: (cl/cd)*(anglesconverged/21)^10
    // 6 bezier points for upper and lower: u1, u2, u3, u4, u5, u6,
    // l1,l2,l3,l4,l5,l6
    // x can vary a bit not too much
    struct Airfoil {
        //important stuff
        int id;
        int generation;
        BezierPoint chromosome[2][6]; //bezier curve values 18
        double fitness;
        double ldmax;

        //fun logistic stuff
        int parent_id_1;
        int parent_id_2;
        //file variable as well where its polar is located
    };

    std::vector<Airfoil> Population;

    double fitnessfunction = 6;
    std::vector<Airfoil>CurrentGen;
    std::vector<Airfoil>Repro;
    std::vector<Airfoil>NextGen;
    std::vector<Airfoil>archive;
    public:

    void GeneratePop();
    void RUNTHEGAUNTLET();
    void Reproduce();
    void Mutate();
};






#endif