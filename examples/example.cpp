#include <zstring_view.hpp>

#include <iostream>
#include <string>
#include <string_view>
#include <print>

using namespace std::literals;

std::string_view to_string(std::strong_ordering order) {
    if (order == std::strong_ordering::equal) {
        return "equal";
    } else if (order == std::strong_ordering::equivalent) {
        return "equivalent";
    } else if (order == std::strong_ordering::less) {
        return "less";
    } else if (order == std::strong_ordering::greater) {
        return "greater";
    } else {
        assert(false);
    }
}

int main() {
    std::string s = "hello world";
    std::zstring_view z0 = "hello";
    std::zstring_view z1 = s;
    std::zstring_view empty;
    std::println("{}", z0);
    std::println("{}", s.starts_with(z0));
    std::println("{}", z0.starts_with(s));
    std::println("{}", z0.starts_with("hello"));
    std::println("{}", z0.starts_with("hello"zsv));
    std::println("{}", std::hash<std::zstring_view>{}(z1));
    std::cout<<z1<<std::endl;
    std::println("{}", "hello"zsv == "hello"sv);
    std::println("{}", "hello"zsv == "hello"zsv);
    std::println("{}", "hello"zsv != "goodbye"sv);
    std::println("{}", "hello"zsv != "goodbye"zsv);
    std::println("{}", z0 == z1);
    std::println("{}", to_string(z0 <=> z1));
    std::println("{}", z0[z0.size()] * 1);
    std::println("{}", z0.c_str());
    std::println("\"{}\"", empty);
    std::println("{}", empty == ""zsv);
    std::formatter<std::string_view> f;
    
    std::wstring ws = L"hello world";
    std::wzstring_view wz0 = L"hello";
    std::wzstring_view wz1 = ws;
    std::wzstring_view wempty;
    std::wcout << std::format(L"{}\n", wz0);
    std::println("{}", ws.starts_with(wz0));
    std::println("{}", wz0.starts_with(ws));
    std::println("{}", wz0.starts_with(L"hello"));
    std::println("{}", wz0.starts_with(L"hello"zsv));
    std::println("{}", std::hash<std::wzstring_view>{}(wz1));
    std::wcout<<wz1<<std::endl;
    std::println("{}", L"hello"zsv == L"hello"sv);
    std::println("{}", L"hello"zsv == L"hello"zsv);
    std::println("{}", L"hello"zsv != L"goodbye"sv);
    std::println("{}", L"hello"zsv != L"goodbye"zsv);
    std::println("{}", wz0 == wz1);
    std::println("{}", to_string(wz0 <=> wz1));
    std::println("{}", wz0[wz0.size()] * 1);
    std::wcout << std::format(L"{}\n", wz0.c_str());
    std::wcout << std::format(L"\"{}\"\n", wempty);
    std::println("{}", wempty == L""zsv);
    std::formatter<std::wstring_view, wchar_t> wf;
}
