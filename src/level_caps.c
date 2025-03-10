#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "level_caps.h"
#include "pokemon.h"

const u16 sLevelCapFlagMap[][2] =
{
    {FLAG_BADGE01_GET, 15},
    {FLAG_BADGE02_GET, 20},
    {FLAG_BADGE03_GET, 25},
    {FLAG_BADGE04_GET, 30},
    {FLAG_BADGE05_GET, 35},
    {FLAG_BADGE06_GET, 40},
    {FLAG_BADGE07_GET, 45},
    {FLAG_BADGE08_GET, 50},
    {FLAG_IS_CHAMPION, 60},
};

u8 GetCurrentLevelCap(void)
{
    u8 i;

    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (!FlagGet(sLevelCapFlagMap[i][0]))
                return sLevelCapFlagMap[i][1];
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }

    return MAX_LEVEL;
}

const u16 sExpScalingDown[5] = { 4, 8, 16, 32, 64 };
const u16 sExpScalingUp[5]   = { 16, 8, 4, 2, 1 };

u16 GetSoftLevelCapExpValue(u8 level, u32 expValue)
{
    u8 levelDifference;
    u8 currentLevelCap = GetCurrentLevelCap();

    if (B_EXP_CAP_TYPE == EXP_CAP_NONE)
        return expValue;

    if (B_LEVEL_CAP_EXP_UP && level < currentLevelCap)
    {
        levelDifference = currentLevelCap - level;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown))
            return expValue + (expValue / sExpScalingUp[ARRAY_COUNT(sExpScalingDown) - 1]);
        else
            return expValue + (expValue / sExpScalingUp[levelDifference]);
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_SOFT && level >= currentLevelCap)
    {
        levelDifference = level - currentLevelCap;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown))
            return expValue / sExpScalingDown[ARRAY_COUNT(sExpScalingDown) - 1];
        else
            return expValue / sExpScalingDown[levelDifference];
    }
    else
        return 0;

}
