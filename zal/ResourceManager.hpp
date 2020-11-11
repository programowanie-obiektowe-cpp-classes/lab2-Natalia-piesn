#pragma once

#include "Resource.hpp"

class ResourceManager
{
  Resource* res;

public:

    ResourceManager()
    {
      res = new Resource;
    }

    ResourceManager(const ResourceManager& res_man) : {
      res = new Resource{*res_man.res}
    };

    ResourceManager(ResourceManager&& res_man) : { 
      res = nullptr;
      res = res_man.res;
      res_man.res = nullptr;
      }

    ~ResourceManager() {
      delete res;
    }

    double get() { return res->get(); }

    ResourceManager operator=(const ResourceManager& res_man)
    {
        if (&res_man != this) {
            delete res;
            res = new Resource{*res_man.res}; 
        }
        return *this;
    }

    ResourceManager operator=(ResourceManager&& res_man)
    {
        if (&res_man != this) {
            delete res;
            res = res_man.res;
            res_man.res = nullptr;
        }
        return *this;
    }
};
