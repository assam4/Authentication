#pragma once

// Username and Password Checking createries
static constexpr unsigned Conditions_count = 4;
static constexpr unsigned Minimum_size = 6;
static constexpr unsigned Maximum_size = 20;
static constexpr int Good = 0;
static constexpr int Incorrect_size = 2;
static constexpr int Incorrect_char = 1;

// User prioritety lvls
static constexpr char Admin = 'A';
static constexpr char Moderator = 'M';
static constexpr char Simple_user = 'U';
static constexpr char Guest = 'G';

// stream const values

static constexpr unsigned Ignore_size = 100;
static constexpr char Separator_character = ':';
static constexpr char Beginning_character = '{';
static constexpr char Ending_character = '}';

// file read/writing values

static constexpr int Start = 0;
static constexpr int Empty = 0;

// Authentication values

static const int max_try = 3;
static const char Ok = 'y';
static const char Cancel = 'n';