#pragma once
#include <Windows.h>
#include <cstdio>

#include "ST3.hpp"
#include "Variables.hpp"
#include "Minhook/MinHook.h"

// this .hpp file is practically useless but im too lazy to delete it :sleeping:

void SetTimescale(float amount)
{
    ((void(*)(float))(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Time::set_timeScale))(amount);
}