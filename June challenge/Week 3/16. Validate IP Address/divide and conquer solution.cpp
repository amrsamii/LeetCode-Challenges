class Solution {
public:
    bool validateIPv4(string IP) {
        if (IP.empty())
            return false;
        
        vector<string> groups;
        string token;
        istringstream iss(IP);

        while (getline(iss, token, '.')) {
            groups.push_back(token);
        }

        if (IP.back() == '.')
            groups.emplace_back("");

        if (groups.size() != 4)
            return false;

        for (auto group : groups) {
            if (group.length() == 0 || group.length() > 3)
                return false;

            if (group[0] == '0' && group.length() > 1)
                return false;

            for (auto ch : group) {
                if (!isdigit(ch))
                    return false;
            }

            if (stoi(group) > 255)
                return false;
        }
        return true;
    }

    bool validateIPv6(string IP) {
        if (IP.empty())
            return false;
        
        vector<string> groups;
        string token;
        istringstream iss(IP);

        while (getline(iss, token, ':')) {
            groups.push_back(token);
        }

        if (IP.back() == ':')
            groups.emplace_back("");

        if (groups.size() != 8)
            return false;

        for (auto group : groups) {
            if (group.length() == 0 || group.length() > 4)
                return false;

            for (auto ch : group) {
                if (!isdigit(ch) && (ch > 'f' || ch < 'a') && (ch > 'F' || ch < 'A'))
                    return false;
            }
        }
        return true;
    }

    string validIPAddress(string IP) {
        if (validateIPv4(IP))
            return "IPv4";

        if (validateIPv6(IP))
            return "IPv6";

        return "Neither";
    }
};
