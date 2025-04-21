#include "philo.h"

void printphilo(t_philo *philo)
{
	int i = 0;
	i  = 0;
while(i < philo[i].info->num_phi)
{
	printf("id:%d===>" ,philo[i].id);
	printf("num:%d ttd:%d tte:%d tts:%d\n", philo[i].info->num_phi
		,philo[i].info->ttd ,philo[i].info->tte ,philo[i].info->tts);

	i++;
}
}
