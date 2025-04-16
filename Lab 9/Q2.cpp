#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Logger {
	private:
	    vector<string> logs;
	    const int maxLogs = 1000;
	
	    void addLog(const string& severity, const string& module, const string& message) {
	        string formatted = "[" + severity + "] [" + module + "] " + message;
	
	        if (logs.size() >= maxLogs) {
	            logs.erase(logs.begin()); // remove oldest log
	        }
	
	        logs.push_back(formatted);
	    }
	
	public:
	    void logInfo(const string& module, const string& message) {
	        addLog("INFO", module, message);
	    }
	
	    void logWarning(const string& module, const string& message) {
	        addLog("WARNING", module, message);
	    }
	
	    void logError(const string& module, const string& message) {
	        addLog("ERROR", module, message);
	    }
	    
	    friend class Auditor;
};

class Auditor {
	private:
	    string authToken;
	
	    bool isAuthenticated() const {
	        return authToken == "secure_123";
	    }
	
	public:
	    Auditor(const string& token) : authToken(token) {}
	
	    vector<string> retrieveLogs(const Logger& logger) const {
	        if (isAuthenticated()) {
	            return logger.logs; 
	        } else {
	            cout << "Access denied: Auditor not authenticated." << endl;
	            return {};
	        }
	    }
};

void simulateNetworkModule(Logger& logger) {
    logger.logInfo("Network", "Connection established.");
    logger.logWarning("Network", "Latency spike.");
    logger.logError("Network", "Connection dropped.");
}

void simulateDatabaseModule(Logger& logger) {
    logger.logInfo("Database", "Query successful.");
    logger.logWarning("Database", "Slow transaction.");
    logger.logError("Database", "Failed to connect.");
}

int main() {
    Logger logger;

    simulateNetworkModule(logger);
    simulateDatabaseModule(logger);

    Auditor authAuditor("secure_123");
    vector<string> logs = authAuditor.retrieveLogs(logger);
    
    cout << "\n--- Logs Retrieved by Authenticated Auditor ---\n";
    for (const string& log : logs) {
        cout << log << endl;
    }

    Auditor unauthAuditor("wrong_token");
    unauthAuditor.retrieveLogs(logger);

    return 0;
}

