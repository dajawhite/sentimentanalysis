#include "Analyzer.h"

int main(int argc, const char** argv)
{
    Analyzer sentiment;

    sentiment.Train(argv);
    sentiment.ProcessTestData(argv);
    sentiment.Classify(argv);
    sentiment.StoreAnswers(argv);
    sentiment.Evaluate(argv);

    return 0;
}