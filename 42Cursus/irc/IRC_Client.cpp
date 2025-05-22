#include "IRC_Client.hpp"

//CONSTRUCTOR

IRC_Client::IRC_Client(int socket_client): _socket_client(socket_client), _client_info(false), _state(NOT_CONNECTED), _role(NONE)
{
    _connect_time = getCurrentDateTime();
    _last_activity = get_time();
}

IRC_Client::IRC_Client(int socket_client, const std::string &host): _socket_client(socket_client), _client_info(false), _state(NOT_CONNECTED), _role(NONE),  _host(host)
{
    _connect_time = getCurrentDateTime();
    _last_activity = get_time();
}

IRC_Client::IRC_Client(const IRC_Client &client): _socket_client(client._socket_client), _client_info(false), _state(NOT_CONNECTED), _role(client._role),  _host(client._host)
{
    _connect_time = getCurrentDateTime();
    _last_activity = get_time();
}

//DESCTRUCTOR

IRC_Client::~IRC_Client()
{
    close(_socket_client);
}

//GETTER/SETTER

int     IRC_Client::get_role() const
{
    return _role;
}

void    IRC_Client::set_role(int role)
{
    _role = role;
}


int     IRC_Client::get_socket_client(void) const
{
    return (_socket_client);
}

void    IRC_Client::set_socket_client(int socket_client)
{
    _socket_client = socket_client;
}

void    IRC_Client::set_username(const std::string &username)
{
    _username = username;
}

std::string    IRC_Client::get_username() const
{
    return (_username);
}

void    IRC_Client::set_nickname(const std::string &nickname)
{
    _nickname = nickname;
}

std::string    IRC_Client::get_nickname() const
{
    return (_nickname);
}

void    IRC_Client::set_client_info(bool value)
{
    _client_info = value;
}

bool    IRC_Client::get_client_info() const
{
    return (_client_info);
}

void    IRC_Client::set_state(int state)
{
    _state = state;
}

int IRC_Client::get_state() const
{
    return (_state);
}

size_t  IRC_Client::get_last_activity() const
{
    return _last_activity;
}

std::string  IRC_Client::get_connect_time() const
{
    return _connect_time;
}


//FUNCTIONS


std::string IRC_Client::getCurrentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buffer[80];

    tstruct = *localtime(&now);

    strftime(buffer, sizeof(buffer), "%d %B %Y %H:%M:%S", &tstruct);
    return std::string(buffer);
}

std::string IRC_Client::get_prefix() const 
{
	return ":" + _nickname + "!" + _username + "@" + _host;
}

void    IRC_Client::close_socket() const
{
    close(_socket_client);
}

void    IRC_Client::fill_input_client(char *buffer, ssize_t size)
{
    if (size == 0)
        return ;
    _input_client.insert(_input_client.end(), buffer, buffer + size);
}

bool    IRC_Client::get_input_client(std::string &line)
{
    size_t i = 0;
    int     r = 0;

    for (; i < _input_client.size() && _input_client[i] != '\n'; i++);
    if (i >= _input_client.size())
        return (false);
    if (*(_input_client.begin() + (i - 1)) == '\r')
        r = 1;
    line = std::string(_input_client.begin(), _input_client.begin() + i - r);
    _input_client.erase(_input_client.begin(), _input_client.begin() + i + 1);
    if (*_input_client.begin() == '\r')
        _input_client.erase(_input_client.begin(), _input_client.begin() + 1);
    return (true);
}

void     IRC_Client::set_output_client(const std::string &str)
{
    this->_output_client.insert(_output_client.end(), str.c_str(), str.c_str() + str.size());
}

bool    IRC_Client::send_output_client()
{
    size_t i = 0;
    if (_output_client.size() == 0) return false;
    for (; i < _output_client.size(); i++)
    {
        if (_output_client[i] == '\n')
            break ;
    }
    if (i >=_output_client.size()) return false;
    std::string response = std::string(_output_client.begin(), _output_client.begin() + i + 1);
    _output_client.erase(_output_client.begin(), _output_client.begin() + i + 1);  
    send(this->get_socket_client(), response.c_str(), response.size(), 0);
    if (response.find("PONG"))
        _last_activity = get_time();
    return (true);
}

size_t	IRC_Client::get_time() const
{
	t_time			time;
	size_t			now;

	gettimeofday(&time, NULL);
	now = time.tv_sec;
	return (now);
}
