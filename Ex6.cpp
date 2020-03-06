#include <iostream>


void mon_6(float s, float a1, float a2, float v) {
	float t_min = 0, t_accel = 0, v_cur = 0, t_decel = 0;
	//a2 = -a2;
	//������������ ������������ �������� � ����� ���� � ������, ���� v �� ����������. ������ v(t) - �����������.
	t_min = pow(2 * s * (1 / a1 - 1 / a2), 0.5);
	t_accel = pow(2 * s * (1 / (a2 - a1)) * a2 / a1, 0.5); //�����, ������� ����� ���������� �� ������ ����������
	v_cur = a1 * t_accel; //����������� ����������� ��������

	//���� v ����������, ������������ v_cur �� v. ������ v(t) ������ ����� ��������, ������� - ���������� ����.
	if (v_cur > v) {
		t_accel = v / a1;
		t_decel = -v / a2;
		t_min = 2 * s / v - ((2 * s / v - t_accel - t_decel) / 2);
		v_cur = v;
	}
	std::cout << "min time: " << t_min << "\n" << "max velocity: " << v_cur;
}


int main()
{
	//a2 �� ������ "-", �.�. ��������� ����������� 
	float s = 1000, a1 = 4, a2 = -2, v = 60;	
	mon_6(s,a1,a2,v);
}
