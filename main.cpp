#include <iostream>

class Neuron
{

public:
    long float Error;
    long float Smooth = 0.01;
    long float ProcessData(long float input)
    {
        return input * weight;
    }

    long float RestoreData(long float output)
    {
        return output / weight;
    }

    void Train(long float input, long float expectedResult)
    {
        long float actResult = input * weight;
        Error = expectedResult - actResult;
        long float correction = (Error / actResult) * Smooth;
        weight += correction;
    }

private:
    long float weight = 0.5;

};

int main()
{
    //You can choose any unit of measure (And also enter the current rate if you are going to convert funds)

    long float usd = 1;
    long float eur = 0.93;

    //Example with other parameters
    /*
        long float km = 1;
        long float meters = 1000;
    */

    int userInput;
    std::cout << "Enter euro: ";
    std::cin >> userInput;

    Neuron neuron = Neuron();

    int i = 0;
    do
    {
        i++;
        //You can choose any unit of measure
        neuron.Train(usd, eur);

        //  Output every iteration!
        std::cout << "Iteration: " << i << "\t\tError: " << neuron.Error << "\n";

        //  Output every i iteration!
        /*
            if (i % 11 == 0) {
            std::cout << "Iteration: " << i << "\t\tError: " << neuron.LastError << "\n";
            }
        */

    } while (neuron.Error > neuron.Smooth || neuron.Error < -neuron.Smooth);

    std::cout << "\n[" << userInput << "] euro is [" << neuron.RestoreData(userInput) << "] dollars.\n";

    //Reverse conversion
    //std::cout << "\n[" << input << "] dollars is [" << neuron.ProcessData(input) << "] euro.\n";

}