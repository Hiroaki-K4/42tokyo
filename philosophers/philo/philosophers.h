/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:29:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/29 18:35:20 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// int increment(int i);

#ifdef __cplusplus
extern "C"{
#endif /*__cplusplus */

	int increment(int i);

#ifdef __cplusplus
}
#endif /*__cplusplus */


#endif
