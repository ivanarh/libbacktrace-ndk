#include "logging.h"
#include <sstream>

namespace android {
    namespace base {
        class LogMessageData {
        public:
            std::ostringstream ostream;
        };

        LogMessage::LogMessage(const char *file, unsigned int line, LogId id,
                               LogSeverity severity, int error)
        : data_(new LogMessageData)
        {
        }

        LogMessage::~LogMessage() {
        }

        std::ostream& LogMessage::stream() {
            return data_->ostream;
        };
    }
}