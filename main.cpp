#include <cstring>
#include <iostream>
#include <matio.h>

#include <MatConfigParser.h>

int main() {
    matConfigParser configParser;


    std::vector<std::string> UserVariables;

    UserVariables.reserve(1);
    UserVariables.push_back("config_struct");
    UserVariables.push_back("double_array2");

    std::map<std::string, std::any> TypeCastedUserVariables;

    auto start = std::chrono::high_resolution_clock::now(); // başlangıç süresi
    TypeCastedUserVariables = configParser.ParseConfigMatFile("data-me.mat", readOnlyMode, UserVariables);
    auto end = std::chrono::high_resolution_clock::now();   // bitiş süresi

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);  // süre hesaplaması
    std::cout << "The function took: " << duration.count() << " seconds." << std::endl; //süreyi yazdır

    double* double_array = std::any_cast<double*>(TypeCastedUserVariables["double_array"]);
    double* BeamNumber = std::any_cast<double*>(TypeCastedUserVariables["BeamNumber"]);
    double* MinBearingResolution = std::any_cast<double*>(TypeCastedUserVariables["MinBearingResolution"]);
    double* ArrayLength = std::any_cast<double*>(TypeCastedUserVariables["ArrayLength"]);
    double* BeamformerType = std::any_cast<double*>(TypeCastedUserVariables["BeamformerType"]);
    std::shared_ptr<char[]> LogPath = std::any_cast<std::shared_ptr<char[]>>(TypeCastedUserVariables["LogPath"]);
    uint8_t* IsFullPast = std::any_cast<uint8_t*>(TypeCastedUserVariables["IsFull"]); bool IsFull = (*IsFullPast != 0);
    float* single_array = std::any_cast<float*>(TypeCastedUserVariables["single_array"]);
    double* random_array = std::any_cast<double*>(TypeCastedUserVariables["random_array"]);

    double* double_array2 = std::any_cast<double*>(TypeCastedUserVariables["double_array2"]);

    std::cout << "\n" << "double_array: " << double_array[0];
    std::cout << "\n" << "BeamNumber: " <<BeamNumber[0];
    std::cout << "\n" << "MinBearingResolution: " <<MinBearingResolution[0];
    std::cout << "\n" << "ArrayLength: " <<ArrayLength[0];
    std::cout << "\n" << "BeamformerType: " <<BeamformerType[0];
    std::cout << "\n" << "Logpath: " <<LogPath;
    std::cout << "\n" << "IsFull: " <<((IsFull==1)?"Full":"NotFull");
    std::cout << "\n" << "single_array: " << single_array[0];
    std::cout << "\n" << "random_array: " << random_array[0] << "\n";

    std::cout << "\n" << "double_array2: " << double_array2[0] << "\n\n";


    // -----------------------------------------

//    // Open the MAT file
//    mat_t *matfp = Mat_Open("data-me.mat", 0);
//    if (NULL == matfp) {
//        std::cerr << "Error opening MAT file: " << "data-me.mat" << "\n";
//        exit(-1);
//    }

//    auto start = std::chrono::high_resolution_clock::now(); // başlangıç süresi

//    matvar_t* configStruct = Mat_VarRead(matfp, "config_struct");
//    //matvar_t* doubleArray2 = Mat_VarRead(matfp, "double_array2");

//    auto end = std::chrono::high_resolution_clock::now();   // bitiş süresi

//    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);  // süre hesaplaması
//    std::cout << "The function took: " << duration.count() << " seconds." << std::endl; //süreyi yazdır

    return 0;
}
