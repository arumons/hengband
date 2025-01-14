﻿#pragma once

#include "object-enchant/tr-types.h"
#include "system/angband.h"

class ObjectType;
class PlayerType;

bool potion_smash_effect(PlayerType *player_ptr, MONSTER_IDX who, POSITION y, POSITION x, KIND_OBJECT_IDX k_idx);
PERCENTAGE breakage_chance(PlayerType *player_ptr, ObjectType *o_ptr, bool has_archer_bonus, SPELL_IDX snipe_type);

class ObjectBreaker {
protected:
    ObjectBreaker(tr_type ignore_flg);

public:
    virtual ~ObjectBreaker() = default;
    bool can_destroy(ObjectType *o_ptr) const;
    virtual bool hates(ObjectType *o_ptr) const = 0;

private:
    tr_type ignore_flg;
};

class BreakerAcid : public ObjectBreaker {
public:
    BreakerAcid();
    virtual ~BreakerAcid() = default;
    bool hates(ObjectType *o_ptr) const;
};

class BreakerElec : public ObjectBreaker {
public:
    BreakerElec();
    virtual ~BreakerElec() = default;
    bool hates(ObjectType *o_ptr) const;
};

class BreakerFire : public ObjectBreaker {
public:
    BreakerFire();
    virtual ~BreakerFire() = default;
    bool hates(ObjectType *o_ptr) const;
};

class BreakerCold : public ObjectBreaker {
public:
    BreakerCold();
    virtual ~BreakerCold() = default;
    bool hates(ObjectType *o_ptr) const;
};
