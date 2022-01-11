#include <iostream>
#include <cstring>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <queue>
#include <deque>

class ProblemBase2
{
public:
	virtual int GetInput() = 0;
	virtual void RunAlgorithm() = 0;

	void Loop() {
		while (GetInput() != EOF) {
			RunAlgorithm();
		}
	}
private:
};

class ConSimulator : public ProblemBase2
{
public:
	struct Statement
	{
		int time_remain;
		std::string statement;
	};
	virtual int GetInput() override
	{
		std::string input;
		std::getline(std::cin, input);
		std::istringstream ss(input);
		ss >> m_prog_num;		
		for (int i = 0; i < MAX_STATEMENTS; ++i) {
			ss >> m_statements[i];			
		}
		ss >> m_quantum;
		
		for (int i = 1; i <= m_prog_num; ++i) {
			std::queue<Statement> program;
			do
			{
				Statement state;
				std::getline(std::cin, state.statement);				
				state.time_remain = -1;
				bool is_end{ false };
				if (state.statement == "end") {
					is_end = true;
				}
				program.push(std::move(state));
				if (is_end) {
					break;
				}
			} while (true);
			m_programs.push_back(std::move(program));
		}
		return 0;
	}

	virtual void RunAlgorithm() override
	{
		memset(m_vars, 0, sizeof(m_vars));
		for (int i = 0; i < m_prog_num; ++i) {
			m_ready.push_back(i);			
		}
		while (!m_ready.empty()) {
			int program_id = m_ready.front();
			auto &state = m_programs[program_id].front();
			if (state.statement == "lock") {
				if (state.time_remain <= 0) {
					state.time_remain = m_statements[2];
				}
				if (m_has_locked) {
					m_blocked.push(program_id);
				}
				else
				{
					state.time_remain -= m_quantum;
					if (state.time_remain <= 0) {
						m_has_locked = true;
						m_programs[program_id].pop();
					}
					m_ready.pop_front();
					m_ready.push_back(program_id);
				}
			}
			else if (state.statement == "unlock") {
				if (state.time_remain <= 0) {
					state.time_remain = m_statements[3];
				}
				state.time_remain -= m_quantum;
				if (state.time_remain <= 0) {
					m_has_locked = false;
					m_programs[program_id].pop();
					if (!m_blocked.empty()) {
						int id = m_blocked.front();
						m_blocked.pop();
						m_ready.push_front(id);
					}
				}
				m_ready.pop_front();
				m_ready.push_back(program_id);
			}
			else if (state.statement == "end") {
				if (state.time_remain <= 0) {
					state.time_remain = m_statements[4];
				}
				state.time_remain -= m_quantum;
				if (state.time_remain <= 0) {
					m_programs[program_id].pop();
					m_ready.pop_front();
				}
				else
				{
					m_ready.pop_front();
					m_ready.push_back(program_id);
				}
			}
			else if (!strncmp(state.statement.c_str(), "print", 5)) {
				if (state.time_remain <= 0) {
					state.time_remain = m_statements[1];
				}
				state.time_remain -= m_quantum;
				if (state.time_remain <= 0) {
					char var[5];
					sscanf(state.statement.c_str() + 5, "%s", var);
					printf("%d: %d\n", program_id + 1, m_vars[var[0] - 'a']);
					m_programs[program_id].pop();
				}
				m_ready.pop_front();
				m_ready.push_back(program_id);
			}
			else // assignment
			{
				if (state.time_remain <= 0) {
					state.time_remain = m_statements[0];
				}
				state.time_remain -= m_quantum;
				if (state.time_remain <= 0) {
					char var[5], equal[5];
					int value{};
					sscanf(state.statement.c_str(), "%s%s%d", var, equal, &value);
					m_vars[var[0] - 'a'] = value;
					m_programs[program_id].pop();
				}
				m_ready.pop_front();
				m_ready.push_back(program_id);
			}
		}
	}

private:
	const static int MAX_STATEMENTS = 5;
	const static int MAX_STATE_LEN = 256;

	bool m_has_locked{ false };
	int m_prog_num;
	int m_statements[MAX_STATEMENTS];
	int m_quantum;
	char m_buffer[MAX_STATE_LEN];
	std::vector<std::queue<Statement>> m_programs;
	//std::deque<Statement> m_ready;
	std::deque<int> m_ready;
	std::queue<int> m_blocked;
	int m_vars[26];
};

int main()
{
	ConSimulator sim;
	sim.Loop();
	return 0;
}