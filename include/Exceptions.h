class ExceptionConfigNotFound {
public:
	const char* what() {
		return "Config file not found.";
	}
};

class ExceptionRequestsNotFound {
public:
	const char* what() {
		return "Requests file not found.";
	}
};

class ExceptionFileNotFound {
public:
	const char* what() {
		return "File not found.";
	}
};