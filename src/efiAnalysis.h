#include "efiUtils.h"
#include "efiSmmUtils.h"

namespace efiAnalysis {
class efiAnalyzer {
  public:
    bool findImageHandleX64();
    bool findSystemTableX64();
    ea_t findBootServicesTableX64();
    ea_t findRuntimeServicesTableX64();

    void getBootServicesX64();
    void getBootServicesX86();

    void getProtNamesX64();
    void getProtNamesX86();

    void printProtocols();
    void markProtocols();
    void markDataGuids();

    bool findSmmCallout();

    void dumpInfo();

    efiAnalyzer();
    ~efiAnalyzer();

  private:
    ea_t base;
    ea_t startAddress;
    ea_t endAddress;
    ea_t mainAddress;
    path guidsJsonPath;
    json bootServices;
    json dbProtocols;
    vector<json> allProtocols;
    vector<ea_t> markedProtocols;
};

bool efiAnalyzerMainX64();
bool efiAnalyzerMainX86();
}; // namespace efiAnalysis