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

    void Train(long float input, long float expResult)
    {
        long float actResult = input * weight;
        Error = expResult - actResult;
        long float correction = (Error / actResult) * Smooth;
        weight += correction;
    }

private:
    long float weight = 0.5;

};

int main()
{
    long float usd = 1;
    long float rub = 77.23;
    int input;

    std::cout << "Enter rubles: ";
    std::cin >> input;
    std::cout << "\n";

    Neuron neuron = Neuron();

    int i = 0;
    do
    {
        i++;
        neuron.Train(usd, rub);

        //  Output every iteration!
        std::cout << "Iteration: " << i << "\t\tError: " << neuron.Error << "\n";

        //  Output every n iteration!
        /*
            if (i % 11 == 0) {
            std::cout << "Iteration: " << i << "\t\tError: " << neuron.LastError << "\n";
            }
        */

    } while (neuron.Error > neuron.Smooth || neuron.Error < -neuron.Smooth);

    std::cout << "\n[" << input << "] rubles is [" << neuron.RestoreData(input) << "] dollars.\n";

}