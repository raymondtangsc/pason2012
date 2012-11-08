#pragma once

#include <string>

class MessageFactory {
public:
    MessageFactory();
    ~MessageFactory();
    std::string const& CreateInitMessage(std::string const& matchToken) const;
    bool ParseInitReply(std::string const& reply);
    std::string const& CreateMoveMessage(std::string const& moveS) const;
    bool ParseMoveReply(std::string const& reply) const;
    bool ParseStateMessage(std::string const& stateS) const;
    std::string const& GetClientToken() const;
private:
    void PrintErrorMessage(std::string const& message) const;
    std::string m_clientToken;
};

