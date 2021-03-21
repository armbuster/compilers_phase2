#include "gtest/gtest.h"
#include "IrEnums.h"

TEST(IrEnums, testBinAdd) 
{
    ir::OpCode::BinOp testBinOp = ir::OpCode::BinOp::ADD;

    // std::cout << "testBinOp=" << testBinOp << std::endl;

    ASSERT_EQ(testBinOp, ir::OpCode::BinOp::ADD);
}