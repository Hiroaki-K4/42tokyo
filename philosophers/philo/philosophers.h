/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:29:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/29 22:11:33 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval {
    time_t tv_sec;            /* Seconds.  */
    suseconds_t tv_usec;      /* Microseconds.  */
};

#ifdef __cplusplus
extern "C"{
#endif /*__cplusplus */

	int increment(int i);
	int	ft_atoi(const char *nptr);

#ifdef __cplusplus
}
#endif /*__cplusplus */


#endif
