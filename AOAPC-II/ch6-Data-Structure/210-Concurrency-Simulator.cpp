#include <iostream>
#include <cstring>
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
		int ID;
		int time_remain;
		int type;
		std::string statement;
	};
	virtual int GetInput() override
	{
		auto rst = scanf("%d", &m_prog_num);
		if (rst == EOF)
			return EOF;
		for (int i = 0; i < MAX_STATEMENTS; ++i) {
			scanf("%d", &m_statements[i]);
		}
		scanf("%d", &m_quantum);
		for (int i = 1; i <= m_prog_num; ++i) {
			std::queue<Statement> program;
			do
			{
				scanf("%s", m_buffer);
				Statement state;
				state.statement = m_buffer;
				state.ID = i;
				// TODO: parse statement type
				state.time_remain = ;
				program.push(std::move(state));
				if (!strcmp(m_buffer, "end")) {
					break;
				}
			} while (true);
			m_programs.push_back(std::move(program));
		}
		return 0;
	}

	virtual void RunAlgorithm() override
	{
		for (int i = 0; i < m_prog_num; ++i) {
			m_ready.push_back(m_programs[i].front());
			m_programs[i].pop();
		}
		while (!m_ready.empty()) {
			auto &state = m_ready.front();
			if (state.statement == "lock") {
				
			}
			else if (state.statement == "unlock") {

			}
			else if (state.statement == "end") {

			}
			else if (!strncmp(state.statement.c_str, "print", 5)) {

			}
			else
			{

			}
		}
	}
private:
	const static int MAX_STATEMENTS = 5;
	const static int MAX_STATE_LEN = 256;
	int m_prog_num;
	int m_statements[MAX_STATEMENTS];
	int m_quantum;
	char m_buffer[MAX_STATE_LEN];
	std::vector<std::queue<Statement>> m_programs;
	std::deque<Statement> m_ready;
};