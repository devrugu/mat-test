#include <cstring>
#include <iostream>
#include <matio.h>

#include "/home/operator/qt-projects/UtilitiesLibrary/src/ConfigurationParser/mat/sources/MatConfigParser.cpp"

int main() {
    matConfigParser configParser;


    std::vector<std::string> UserVariables;

    UserVariables.reserve(2);
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

//   _______________________________________________________________________
//  |-----------------------------------------------------------------------|
//  |-----------------------------------------------------------------------|
//   -----------------------------------------------------------------------

//    mat_t *matfp = Mat_Open("data-me.mat", MAT_ACC_RDONLY);
//    matvar_t *matvar = Mat_VarRead(matfp, "simple_string");

//    if (matvar != NULL) {
//        if (matvar->class_type == MAT_C_CHAR && matvar->data_type == MAT_T_UINT16) {
//            uint16_t* uint16Data = static_cast<uint16_t*>(matvar->data);
//            size_t numElements = matvar->dims[0] * matvar->dims[1];

//            // Convert the uint16_t data to a C++ wstring (wide string)
//            std::wstring wideString(uint16Data, uint16Data + numElements);

//            // Optionally convert wstring to regular string if needed
//            // This will work correctly only for characters representable in the current locale.
//            std::string value(wideString.begin(), wideString.end());

//            // Now you have the string value stored in 'value'
//            std::cout << "Read value: " << value << std::endl;

//        } else {
//            // Handle error or perform another task
//        }
//        Mat_VarFree(matvar);
//    } else {
//        // Variable not found in the MAT file
//    }

//    Mat_Close(matfp);

    return 0;
}
