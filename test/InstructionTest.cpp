#include "gtest/gtest.h"
#include "Instruction.h"

//SEE: https://chromium.googlesource.com/external/github.com/pwnall/googletest/+/HEAD/googletest/docs/primer.md

TEST(Instruction, test1) 
{
    ir::Instruction* testInst = new ir::Instruction();

    ASSERT_TRUE(true);
}