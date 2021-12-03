#include <gtest/gtest.h>
#include <string>
#include "./../src/operacionSuma.h"

using namespace std;

namespace {
    TEST(OperacionSuma_Test, Test_Resultado) {

        Operacion *operacionSuma = new OperacionSuma();

        string actual = operacionSuma->Ejecute("2 + 3");
        string esperado = "5";

        EXPECT_EQ(esperado, actual);
    }
}