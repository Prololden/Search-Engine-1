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