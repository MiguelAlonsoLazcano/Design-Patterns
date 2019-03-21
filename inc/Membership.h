/*
 * Implementing State Pattern
 * Changing object state represented by Membership Account class,
 * Object states are represented by the corresponding classes.
 *
 * */

#pragma  once

#include <iostream>
#include <string>

class Membership {
public:
    Membership(const std::string& n) : _name(n){}

    const std::string& name() { return _name; }
    virtual int downloads_per_day() const = 0;
    virtual Membership* upgrade() const = 0;
private:
    std::string _name;
};

class PremiumMember : public Membership
{
public:
    PremiumMember() : Membership("Premium") {}

    /*
     * Premium members have ten to five download per day
     * */
    int downloads_per_day() const override {
        return 10;
    }

    virtual Membership* upgrade() const override {
        std::cout << "  * already Premium" << std::endl;
        return new PremiumMember();
    }
};

class BasicMember : public Membership
{
public:
    BasicMember() : Membership("Basic") {}

    /*
     * Basic members have up to five download per day
     * */
    int downloads_per_day() const override {
        return 5;
    }

    virtual Membership* upgrade() const override {
        std::cout << "  * Basic, upgrade to Premium" << std::endl;
        return new PremiumMember();
    }
};

class FreeTier : public Membership
{
public:
    FreeTier() : Membership("Free") {}

    /*
     * Free members have one download per day
     * */
    int downloads_per_day() const override {
        return 1;
    }

    virtual Membership* upgrade() const override {
        std::cout << "  * Free, upgrade to basic" << std::endl;
        return new BasicMember();
    }
};

class Member
{
public:
    Member(const std::string &n) : _name(n), current_downloads(0), _role(new FreeTier()){}

    const std::string& name() { return _name; }

    bool can_download() const {
        return (_role->downloads_per_day() - current_downloads) > 0;
    }

    bool download(){
        if (can_download()){
            ++current_downloads;
            return true;
        }
        return false;
    }

    int download_per_day() {
        return _role->downloads_per_day();
    }

    void upgrade(){
        _role = _role->upgrade();
    }

private:
    Membership *_role;
    std::string _name;
    int current_downloads;
};