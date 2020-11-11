#pragma once

#include "Resource.hpp"

class ResourceManager
{
    Resource res;

    ResourceManager(const ResourceManager& res_man) : res{res_man.res} {};

    ResourceManager(ResourceManager&& res_man) : res() { res = res_man.res; }

    ~ResourceManager() {}

    double get() { return res.get(); }

    ResourceManager operator=(const ResourceManager& res_man)
    {
        if (&res_man == this) {
            return *this;
        }
        else {
            res = res_man.res;
        }
        return *this;
    }

    ResourceManager operator=(ResourceManager&& res_man)
    {
        if (&res_man == this) {
            return *this;
        }
        else {
            res = res_man.res;
        }
        return *this;
    }
};
