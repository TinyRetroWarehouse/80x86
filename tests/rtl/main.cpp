#include <memory>
#include <string>

#include <gtest/gtest.h>

#include "RTLCPU.h"

std::unique_ptr<CPU> get_cpu(const std::string &test_name)
{
    return std::make_unique<RTLCPU<>>(test_name);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::GTEST_FLAG(filter) += "\
-CmpsRepe/Cmps16Fixture.*:\
CmpsRepe/Cmps8Fixture.*:\
CmpsRepne/Cmps16Fixture.*:\
CmpsRepne/Cmps8Fixture.*:\
Div/DivMem16Test.*:\
Div/DivMem8Test.*:\
Div/DivReg16Test.*:\
Div/DivReg8Test.*:\
EmulateFixture.Aaa:\
EmulateFixture.Aad:\
EmulateFixture.AadSigned:\
EmulateFixture.Aam:\
EmulateFixture.Aam129:\
EmulateFixture.AamDivByZero:\
EmulateFixture.AamSigned:\
EmulateFixture.Aas:\
EmulateFixture.CbwNegative:\
EmulateFixture.CbwPositive:\
EmulateFixture.CmpsbDec:\
EmulateFixture.CmpswDec:\
EmulateFixture.CwdNegative:\
EmulateFixture.CwdPositive:\
EmulateFixture.DSSegmentOverrideIsNop:\
EmulateFixture.Daa:\
EmulateFixture.Das:\
EmulateFixture.Hlt:\
EmulateFixture.IntoNotTaken:\
EmulateFixture.IntoTaken:\
EmulateFixture.JcxzNotTaken:\
EmulateFixture.JcxzTaken:\
EmulateFixture.Lock:\
EmulateFixture.Lodsb:\
EmulateFixture.LodsbDec:\
EmulateFixture.Lodsw:\
EmulateFixture.LodswDec:\
EmulateFixture.LoopNotTaken:\
EmulateFixture.LoopTaken:\
EmulateFixture.LoopeNotTaken:\
EmulateFixture.LoopeNotTakenNonZero:\
EmulateFixture.LoopeTaken:\
EmulateFixture.LoopnzNotTaken:\
EmulateFixture.LoopnzNotTakenNonZero:\
EmulateFixture.LoopnzTaken:\
EmulateFixture.MovsbDec:\
EmulateFixture.MovsbInc:\
EmulateFixture.MovswDec:\
EmulateFixture.MovswInc:\
EmulateFixture.PopMemSegmentOverride:\
EmulateFixture.PushMemSegmentOverride:\
EmulateFixture.ScasbDec:\
EmulateFixture.ScasbDecRepe:\
EmulateFixture.ScasbInc:\
EmulateFixture.ScasbIncRepe:\
EmulateFixture.ScaswDec:\
EmulateFixture.ScaswDecRepe:\
EmulateFixture.ScaswInc:\
EmulateFixture.ScaswIncRepe:\
EmulateFixture.Stosb:\
EmulateFixture.StosbDec:\
EmulateFixture.Stosw:\
EmulateFixture.StoswDec:\
IMul/MulMem16Test.*:\
IMul/MulMem8Test.*:\
IMul/MulReg16Test.*:\
IMul/MulReg8Test.*:\
JmpConditional/JmpFixture.*:\
JmpConditionalAlias/JmpFixture.*:\
Mul/MulMem16Test.*:\
Mul/MulMem8Test.*:\
Mul/MulReg16Test.*:\
Mul/MulReg8Test.*:\
SegmentOverride/MovOverride.*";

    return RUN_ALL_TESTS();
}
