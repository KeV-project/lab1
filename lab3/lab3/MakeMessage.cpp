#include "MakeMessage.h"

string MakeMessage(const int invalidNumber, const int minLimit,
	const int maxLimit, const MessageType& messageType, 
	const string& content)
{
	//TODO: ������� �� ��� ����� � AssertValueInRange, �.�. ���� ����� ��������� ��������� ������, �.�. �� ������� ��������� ���������
	//TODO: � AssertValueInRange, � ���������� �� ������ ���
	switch (messageType)
	{
		case NotInRange:
		{
			string message = "����������: ����� " + to_string(invalidNumber)
				+ "\n�� ������ � ���������� �������� �������� "
				+ "[" + to_string(minLimit) + ", " + to_string(maxLimit)
				+ "]\n� �� ����� ���������� " + content;
			return message;
		}
		case NotPositive:
		{
			string message = "����������: ����� " + to_string(invalidNumber)
				+ " �� �������� �������������\n"
				+ "� �� ����� ���������� " + content;
			return message;
		}
		case NotNonNegative:
		{
			string message = "����������: ����� " + to_string(invalidNumber)
				+ " �� �������� ���������������\n"
				+ "� �� ����� ���������� " + content;
			return message;
		}
		case InvalidTime:
		{
			string message = "����������: " + content
				+ " ������: "
				+ to_string(invalidNumber)
				+ " ���������(/��)" + content + " ��������: "
				+ to_string(maxLimit);
			return message;
		}
	}
}