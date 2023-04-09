#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

struct Town {
    std::string name;
    std::string region;
    int population;
};

int main() {
    std::vector<Town> towns = {
        {"Moscow", "Moscow Oblast", 12655050},
        {"Saint Petersburg", "Leningrad Oblast", 5383880},
        {"Novosibirsk", "Novosibirsk Oblast", 1625631},
        {"Yekaterinburg", "Sverdlovsk Oblast", 1493749},
        {"Nizhny Novgorod", "Nizhny Novgorod Oblast", 1250613},
        {"Kazan", "Tatarstan Republic", 1237381},
        {"Chelyabinsk", "Chelyabinsk Oblast", 1199866},
        {"Omsk", "Omsk Oblast", 1178651},
        {"Samara", "Samara Oblast", 1134730},
        {"Rostov-on-Don", "Rostov Oblast", 1114747},
    };

    std::sort(towns.begin(), towns.end(), [](const auto& a, const auto& b) {
        return a.population < b.population;
        });

    for (const auto& town : towns) {
        std::cout << town.name << " (" << town.region << "): " << town.population << '\n';
    }

    return 0;
}
